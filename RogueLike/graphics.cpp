#include "graphics.h"
#include "utils/config.h"

#define REAL_TIME

namespace graphics {

int w_, h_;

std::vector<std::string> buffer;

void init() {
    init_graphics();
    atexit(shutdown_graphics);
}

void clear_screen() {
    clear();
}

void init_graphics() {
    initscr();
    getmaxyx(stdscr, h_, w_);

    auto map = Config::get_map_parameters();
    h_ = std::min(map["height"] + 1, h_);
    w_ = std::min(map["width"], w_);

    noecho();
    curs_set(0);
    keypad(stdscr, true);
#ifdef REAL_TIME
    timeout(400);
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