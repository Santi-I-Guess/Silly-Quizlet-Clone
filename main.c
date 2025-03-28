#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void the_initials() {
        initscr();
	raw();
        cbreak();
        curs_set(0);
	keypad(stdscr, TRUE);
	noecho();

        start_color();
        init_pair(1, COLOR_WHITE, COLOR_MAGENTA);
        wbkgd(stdscr, COLOR_PAIR(1));

        if (!has_colors()) {
                endwin();
                char message[128] = "\033[31mterminal doesn't support colors. \
                        exiting...\n\033[0m";
                
                fprintf(stderr, "%s\n'", message);
                exit(0);
        }
}

int main(int argc, char *argv[]) {
        the_initials();

        printw("hello world\n");
        refresh();
        getch();

        endwin();
}
