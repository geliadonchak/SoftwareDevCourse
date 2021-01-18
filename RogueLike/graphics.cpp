#include "graphics.h"

namespace graphics {

int w_, h_;

std::vector<std::string> buffer;

void init() {
    init_graphics();
    atexit(shutdown_graphics);
}

void clear_buffer() {
    buffer.assign(24, std::string(80, ' '));
}

void clear_screen() {
    clear();
}

void init_graphics() {
    initscr();
    getmaxyx(stdscr, h_, w_);
    noecho();
    curs_set(0);
    keypad(stdscr, true);
#ifndef NO_REAL_TIME
    timeout(200);
#endif
}

void shutdown_graphics() {
    curs_set(1);
    endwin();
    refresh();
}

int width() {
    return w_;
}

int height() {
    return h_;
}

void write_symbol(symbol_t symbol, int x, int y) {
    if (y < 0 || y >= h_) return;
    if (x < 0 || x >= w_) return;
    mvaddch(y, x, symbol);
}

int input() {
    int c = getch();
    c = getch();
    if (c == KEY_RESIZE) {
        getmaxyx(stdscr, h_, w_);
        return keys_enum::NOTHING;
    }

    return c;
}

void render_frame() {
    refresh();
}

void write_string(const std::string &str, int x, int y) {
    mvaddstr(y, x, str.c_str());
}

}