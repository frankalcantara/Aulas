MDFILES=$(shell find -type f -name '*.md')

SLIDES=$(foreach p,$(subst .md,.slide.html,$(MDFILES)),out/$(p))
HTMLS=$(foreach p,$(subst .md,.html,$(MDFILES)),out/$(p))
PDFS=$(foreach p,$(subst .md,.pdf,$(MDFILES)),out/$(p))

KATEX ?= https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.11.1/

REVEAL_OPTS := -V revealjs-url="https://unpkg.com/reveal.js@3.9.2/"
REVEAL_OPTS += -V theme=moon
REVEAL_OPTS += -V transition=cube
REVEAL_OPTS += --slide-level=2

slides: Makefile $(SLIDES)
all: Makefile $(SLIDES) $(PDFS)

watch:
	echo "$(MDFILES)" | entr make slides

out/%.slide.html: %.md
	pandoc -t revealjs -s -o $@ $< $(REVEAL_OPTS) --katex=$(KATEX) --filter=/home/frank/.local/bin/pandoc-presentation

#out/%.html: %.md
#	pandoc -t html -s -o $@ $< --katex=$(KATEX) --filter=./filter

out/%.pdf: %.md
	pandoc -t latex -s -o $@ $< --filter=/home/frank/.local/bin/pandoc-presentation --resource-path=.:..:out --template=default