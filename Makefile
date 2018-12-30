COMPILE=gcc -Wall -O2 
SRC1:=$(filter-out src/main.c,$(wildcard src/*.c))
SRC2:=$(wildcard src/*/*.c)
SRC:=$(patsubst src/%,%,$(SRC1) $(SRC2))
OBJ:=$(patsubst %.c,ofiles/%.o,$(SRC))
DEP:=$(wildcard src/*.h) $(wildcard src/*/*.h)

all:
	@echo $(OBJ) "|||"  $(DEP)
	mkdir -p $(dir $(OBJ))
	make -f MakefileTests minigimp

minigimp: src/main.c $(OBJ)
	echo "$(@)"
	$(COMPILE) $^ -o $@

ofiles/%.o: src/%.c $(DEP)
	echo target = $@ prereq = $^ 
	gcc -c -o $@ $<
