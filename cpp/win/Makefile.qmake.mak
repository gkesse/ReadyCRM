GSRC = ../code/ReadyCRM/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\rdcrm.exe

all: clean qmake compile run

qmake:
	@qmake
compile: $(GOBJS)
	@mingw32-make
clean:
	@if not exist $(GBIN) @mkdir $(GBIN)
	@if not exist $(GBUILD) @mkdir $(GBUILD)
	@del /q $(GBIN)\*
run:
	@$(GTARGET) $(argv)
