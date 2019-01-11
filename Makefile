COMPILE_P=gcc -Wall -O2 -Isrc
COMPILE_O=gcc -c -Isrc -o
SRC1:=$(filter-out src/main.c, $(wildcard src/*.c))
SRC2:=$(wildcard src/*/*.c)
SRC:=$(patsubst src/%,%,$(SRC1) $(SRC2))
OBJ:=$(patsubst %.c, ofiles/%.o, $(SRC))
DEP:=$(wildcard src/*.h) $(wildcard src/*/*.h)

all: 
	@echo $(OBJ) " | " $(DEP)
	mkdir -p $(dir $(OBJ))
	mkdir -p bin
	make -f Makefile minigimp

minigimp: src/main.c $(OBJ)
	echo $(@)
	$(COMPILE_P) $^ -o bin/$@

ofiles/%.o: src/%.c $(DEP)
	echo target = $@ prereq = $^
	$(COMPILE_O) $@ $<

clean:
	rm -r ofiles bin *.ppm
