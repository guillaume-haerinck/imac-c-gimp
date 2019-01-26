# The use of -Isrc arguments allows us to insert includes without worrying about the file position
# i.e: #include "something.h" instead of "../something.h"
COMPILE_P=gcc -Wall -O2 -Isrc
COMPILE_O=gcc -c -Isrc -o
# Automatically find files in seprarate subfolders
SRC1:=$(filter-out src/main.c, $(wildcard src/*.c))
SRC2:=$(wildcard src/*/*.c)
SRC:=$(patsubst src/%,%,$(SRC1) $(SRC2))
# Make output files having the same name and subfolder as the original but not the same destination
OBJ:=$(patsubst %.c, ofiles/%.o, $(SRC))

DEP:=$(wildcard src/*.h) $(wildcard src/*/*.h)

all: 
	@echo "********************* CHECKING FILES *********************" 
	@echo "" 
	@echo "" 
	@echo " /OO      /OO /OOOOOO /OO   /OO /OOOOOO  /OOOOOO  /OOOOOO /OO      /OO /OOOOOOO " 
	@echo "| OOO    /OOO|_  OO_/| OOO | OO|_  OO_/ /OO__  OO|_  OO_/| OOO    /OOO| OO__  OO" 
	@echo "| OOOO  /OOOO  | OO  | OOOO| OO  | OO  | OO  \__/  | OO  | OOOO  /OOOO| OO  \ OO" 
	@echo "| OO OO/OO OO  | OO  | OO OO OO  | OO  | OO /OOOO  | OO  | OO OO/OO OO| OOOOOOO/" 
	@echo "| OO  OOO| OO  | OO  | OO  OOOO  | OO  | OO|_  OO  | OO  | OO  OOO| OO| OO____/ " 
	@echo "| OO\  O | OO  | OO  | OO\  OOO  | OO  | OO  \ OO  | OO  | OO\  O | OO| OO      " 
	@echo "| OO \/  | OO /OOOOOO| OO \  OO /OOOOOO|  OOOOOO/ /OOOOOO| OO \/  | OO| OO      " 
	@echo "|__/     |__/|______/|__/  \__/|______/ \______/ |______/|__/     |__/|__/      " 
	@echo "" 
	@echo "       »»-------►   By Guillaume HAERINCK & Nicolas LIENART   ◄-------«« " 
	@echo "" 
	@echo "" 
	# Make the same directories in ofiles/ as the architecture in src/
	@mkdir -vp $(dir $(OBJ))
	@mkdir -vp bin
	# When every necessary dirs exist call this makefile again to build the actual program
	@make -f Makefile minigimp

minigimp: src/main.c $(OBJ)
	@echo "********************* BUILDING MINIGIMP *********************" 
	$(COMPILE_P) $^ -o bin/$@ -lm

ofiles/%.o: src/%.c $(DEP)
	@echo "********************* COMPILING $< *********************" 
	$(COMPILE_O) $@ $<

clean:
	@echo "********************* CLEANING FOLDER *********************" 
	@rm -rvf ofiles bin *.ppm
