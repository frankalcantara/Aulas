#!/usr/bin/env stack
-- stack --resolver=lts-16.8 script --package pandoc-types
{-# LANGUAGE OverloadedStrings #-}
module Main where

import Text.Pandoc.JSON
import Text.Pandoc.Walk
import Text.Pandoc.Definition

import Data.Text (Text, unpack)

import Control.Monad.State

import Control.Arrow

main :: IO ()
main = toJSONFilter goDocument

isReveal :: Maybe Format -> Bool
isReveal (Just "revealjs") = True
isReveal _                 = False

goDocument :: Maybe Format -> Pandoc -> Pandoc
goDocument format (Pandoc doc_meta blocks) =
  Pandoc doc_meta (include (isReveal format) . goBlock <$> blocks)

  where
    include :: Bool -> (Block, Bool) -> Block
    include is_reveal (block, is_marked)
       | not is_reveal              = block
       | is_reveal && is_marked     = block
       | is_reveal && not is_marked = Null

goBlock :: Block
        -> ( Block -- The block, with any presentation markers stripped
           , Bool  -- Does this block have any presentation markers
           )
goBlock e@(CodeBlock (_, classes, _) t) =
  (e, "P" `elem` classes || "present" `elem` classes)
goBlock (BlockQuote bs) = (BlockQuote blocks, or marked)
  where (blocks, marked) = unzip $ map goBlock bs 

goBlock (OrderedList attr lis) = (OrderedList attr lis', or marked) where
  (lis', marked) = unzip $ map goBlocks lis

goBlock (BulletList lis) = (BulletList lis', or marked) where
  (lis', marked) = unzip $ map goBlocks lis

goBlock (DefinitionList lis) = (DefinitionList lis', or marked) where
  go_def :: (a, [[Block]]) -> (a, [[Block]], Bool)
  go_def (inlines, blocks) =
    let (blocks', marked) = unzip $ map goBlocks blocks
     in (inlines, blocks', or marked)
  (items, defs, marked) = unzip3 $ map go_def lis
  lis' = zip items defs

goBlock e@(Header _ (_, attr, _) _) =
  (e, "P" `elem` attr || "present" `elem` attr)

goBlock (Div a@(_, attr, _) blocks) = (e', marked) where
  e' = Div a (map (fst . goBlock) blocks)
  marked = "P" `elem` attr || "present" `elem` attr

goBlock block = runState (walkM go block) False where
  go :: Inline -> State Bool Inline
  go (Str p)
    | isPresentationMarker p =
      do put True
         pure (Str "")
    | otherwise = pure (Str p)
  go e = pure e

goBlocks :: [Block] -> ([Block], Bool)
goBlocks = second or . unzip . map goBlock

isPresentationMarker :: Text -> Bool
isPresentationMarker = (||) <$> (== "{.P}") <*> (== "{.present}")