#include <curses.h>
#include <stdbool.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "scripts/drawings.h"
#include "scripts/auxiliary.h"
#include "scripts/mm_handler.h"

void the_initials() {
        setlocale(LC_ALL, "");
        initscr();
        raw();
        cbreak();
        curs_set(0);
        keypad(stdscr, true);
        noecho();

        start_color();
        init_pair(1, COLOR_WHITE, COLOR_MAGENTA); // quizlet-style bkgd
        init_pair(2, COLOR_BLACK, COLOR_WHITE); // main menu text bkgd
        init_pair(3, COLOR_BLACK, COLOR_BLACK);
        wbkgd(stdscr, COLOR_PAIR(1));

        if (!has_colors()) {
                endwin();
                char message[128] = "terminal doesn't support colors. \
                                     Exiting...";

                fprintf(stderr, "\033[31m%s\033[0m\n", message);
                exit(1);
        }
}

extern int main_state;

int main(int argc, char *argv[]) {
        the_initials();
        draw_bkgd_outline();
        
        if (main_state == 0) {
                draw_main_menu();
        }
        getch();

        endwin();
}
