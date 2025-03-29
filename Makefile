
all: final

final: main.c scripts/auxiliary.h scripts/drawings.h scripts/mm_handler.h
	gcc main.c scripts/auxiliary.h scripts/drawings.h scripts/mm_handler.h -o executable_main -lncurses
