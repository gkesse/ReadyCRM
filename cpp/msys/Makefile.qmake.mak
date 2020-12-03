GSRC = ../code/ReadyCRM/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\rdcrm.exe

all: clean qmake compile run

qmake:
	@qmake
compile: $(GOBJS)
	@make
clean:
	@if ! [ -d $(GBIN) ] ; then @mkdir $(GBIN) ; fi
	@if ! [ -d $(GBUILD) ] ; then @mkdir $(GBUILD) ; fi
	@rm -f $(GBIN)\*
run:
	@$(GTARGET) $(argv)
