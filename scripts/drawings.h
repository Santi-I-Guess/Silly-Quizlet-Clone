#include <ncurses.h>
#include <wchar.h>
#define _GNU_SOURCE // feature test macro, see online

// char border_chars[] = "═║╔╗╚╝"; // CANT GET THESE TO WORK!
char outline_chars[] = "012345";

void draw_bkgd_outline() {
        for (int row = 0; row < LINES; ++row) {
                for (int col = 0; col < COLS; ++col) {
                        move(row, col);
                        if (row == 0 && col == 0)
                                addch(outline_chars[2]);
                        else if (row == 0 && col == COLS - 1)
                                addch(outline_chars[3]);
                        else if (row == LINES - 1 && col == 0)
                                addch(outline_chars[4]);
                        else if (row == LINES - 1 && col == COLS - 1)
                                addch(outline_chars[5]);
                        else if (row == 0 || row == LINES - 1)
                                addch(outline_chars[0]);
                        else if (col == 0 || col == COLS - 1)
                                addch(outline_chars[1]);
                }
        }
}

void draw_main_menu() {
        int COL_SEG = COLS / 3;
        int ROW_SEG = LINES / 3;

        // draw shadow
        attron(COLOR_PAIR(3));
        for (int row = ROW_SEG; row < 2*ROW_SEG+1; ++row) {
                for (int col = COL_SEG; col < 2*COL_SEG+1; ++col) {
                        bool on_edge = row != 2*ROW_SEG && col == 2*COL_SEG;
                        bool on_bottom = row == 2*ROW_SEG;
                        if (on_edge || on_bottom) {
                                move(row, col);
                                addch(' ');
                        }
                }
        }

        // draw bkgd
        attron(COLOR_PAIR(2));
        for (int row = ROW_SEG-1; row < 2*ROW_SEG; ++row) {
                for (int col = COL_SEG-1; col < 2*COL_SEG; ++col) {
                        move(row, col);
                        addch(' ');
                }
        }

        // write menu text
        int top_offset = 4;
        int left_offset = COL_SEG + 3;
        move(ROW_SEG + top_offset, left_offset);
        addstr("browse set / folder");
        move(ROW_SEG + top_offset + 1, left_offset);
        addstr("search set");
        move(ROW_SEG + top_offset + 2, left_offset);
        addstr("create folder");
        move(ROW_SEG + top_offset + 3, left_offset);
        addstr("quit");
}
