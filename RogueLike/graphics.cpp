#include "graphics.h"

KEY(NOTHING, -1);
KEY(ARROW_UP, 'w');
KEY(ARROW_LEFT, 'a');
KEY(ARROW_DOWN, 's');
KEY(ARROW_RIGHT, 'd');
KEY(THROW_UP, 'i');
KEY(THROW_LEFT, 'j');
KEY(THROW_DOWN, 'k');
KEY(THROW_RIGHT, 'l');

std::vector<std::string> buffer;

void init() {
    init_graphics();
    atexit(shutdown_graphics);
}

void clear_buffer() {
    buffer.assign(24, std::string(80, ' '));
}

void clear_screen() {
    for (auto i = 0; i < buffer.size(); i++) {
        std::cout << std::endl;
    }
}

void init_graphics() {
    clear_buffer();
}

void shutdown_graphics() {}

int width() {
    return buffer[0].size();
}

int height() {
    return buffer.size();
}

void write_symbol(symbol_t symbol, int x, int y) {
    if (y < 0 || y >= buffer.size()) return;
    if (x < 0 || x >= buffer[y].size()) return;
    buffer[y][x] = symbol;
}

int get_input() {
    int c = std::cin.get();
    return c;
}

void input(int &key_code) {
    key_code = get_input();
}

void render_frame() {
    for (const auto &row : buffer) {
        std::cout << row << std::endl;
    }
    clear_buffer();
}

void write_string(const std::string &str, int x, int y) {
    for (auto c : str) {
        write_symbol(c, x++, y);
    }
}

void draw_state(game &state) {
    state.render();
}