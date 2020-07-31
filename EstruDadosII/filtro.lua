local is_slide = FORMAT == 'revealjs'

setmetatable(_ENV, { __index = function(t, k) return error(k) end })

local function block(x)
  local on_slide = false
  local c = pandoc.walk_block(x, {Str = function(e)
    if e.text == '{.P}' or e.text == '{.present}' then
      on_slide = true
      return pandoc.Null()
    else
      return e
    end
  end})
  print(on_slide or not is_slide, x.t)
  if on_slide or not is_slide then
    return c
  else
    return pandoc.Null()
  end
end

return {
  {
    Para = block,
    BulletList = block,
    OrderedList = block,
    DefinitionList = block,
    BlockQuote = block,
    Table = block,
    Header = function(x)
      local on_slides = false
      for k, v in pairs(x.classes) do
        on_slides = on_slides or v == 'P' or v == 'present'
      end
      if on_slides or not is_slide then
        return x
      else
        return pandoc.Null()
      end
    end,
    CodeBlock = function(x)
      local on_slides = false
      for k, v in pairs(x.classes) do
        on_slides = on_slides or v == 'P' or v == 'present'
      end
      if on_slides or not is_slide then
        return x
      else
        return pandoc.Null()
      end
    end
  }
}
