# ==============================================================================
# This file contains the build routines used for this project. You will use the
# following commands:
#
# make               -  builds the project
# make run           -  runs the built project
# make clean         -  remove binary files
# make gather        -  creates deliverable archive after building project
# make gather-force  -  creates deliverable archive without building project
#
# !!! DO NOT MODIFY THIS FILE !!!
#
# Version: 1.0
# ============================================================================== 
name = project2
location = $(shell pwd)
CXX = clang++
CXXFLAGS = -stdlib=libstdc++ -std=c++1y -Wall -pedantic -g -O3
SRC = $(filter-out src/main.cpp,$(wildcard src/*.cpp))
OBJ = $(subst src/,obj/,$(subst .cpp,.o,$(SRC)))
HPP = $(wildcard src/*.hpp)

.PHONY: all
all: $(name).out

.PHONY: clean
clean:
	rm -f obj/*.o
	rm -f $(name).out
	rm -f $(name)-submission.tar.gz

.PHONY: gather
gather: $(name).out $(name).tar.gz

.PHONY: gather-force
gather-force: $(name).tar.gz

$(name).tar.gz:
	$(eval TMPDIR = $(shell mktemp -d))
	mkdir $(TMPDIR)/$(name)
	cp -r . $(TMPDIR)/$(name)
	rm -f $(TMPDIR)/$(name)/obj/*.o
	rm -f $(TMPDIR)/$(name)/$(name).out
	rm -f $(TMPDIR)/$(name)/$(name)-submission.tar.gz
	find $(TMPDIR) -name '*.swp' -delete
	find $(TMPDIR) -name '*.swo' -delete
	find $(TMPDIR) -name '*~' -delete
	find $(TMPDIR) -name '#*#' -delete
	find $(TMPDIR) -name '*.save' -delete
	find $(TMPDIR) -name '*.save.*' -delete
	find $(TMPDIR) -name '.git' -prune -exec rm -rf {} \; 
	find $(TMPDIR) -name '.svn' -prune -exec rm -rf {} \; 
	cd $(TMPDIR) && tar cvzf "$(location)/$(name)-submission.tar.gz" $(name)
	rm -rf $(TMPDIR)

.PHONY: run
run: $(name).out
	@ ./$(name).out

.PHONY: memcheck
memcheck: $(name).out
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-reachable=yes ./$(name).out

$(name).out: src/main.cpp $(OBJ) $(HPP)
	$(CXX) $(CXXFLAGS) src/main.cpp $(OBJ) -o $(name).out

obj/%.o: src/%.cpp $(HPP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

