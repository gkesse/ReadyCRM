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
git_push:
	@cd $(GPROJECT_PATH) && git pull && git add --all && git commit -m "Initial Commit" && git push -u origin main
git_clone:
	@cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
