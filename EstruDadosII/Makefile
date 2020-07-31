MDFILES=$(shell find -type f -name *.md)

SLIDES=$(foreach p,$(subst .md,.slide.html,$(MDFILES)),out/$(p))
HTMLS=$(foreach p,$(subst .md,.html,$(MDFILES)),out/$(p))
PDFS=$(foreach p,$(subst .md,.pdf,$(MDFILES)),out/$(p))

KATEX ?= https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.11.1/

REVEAL_OPTS := -V revealjs-url="https://unpkg.com/reveal.js@4.0.0/"
REVEAL_OPTS += -V theme=moon
REVEAL_OPTS += --slide-level=2

slides: Makefile $(SLIDES)
all: Makefile $(SLIDES) $(HTMLS) $(PDFS)

out/%.slide.html: %.md
	pandoc -t revealjs -s -o $@ $< $(REVEAL_OPTS) --katex=$(KATEX) --lua-filter=./filtro.lua

out/%.html: %.md
	pandoc -t html -s -o $@ $< --katex=$(KATEX) --lua-filter=./filtro.lua

out/%.pdf: %.md
	pandoc -t latex -s -o $@ $< --lua-filter=./filtro.lua