#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>

#include "utils/types.h"

namespace graphics {

void init();

void clear_screen();

void init_graphics();
void shutdown_graphics();

int width();
int height();

void write_symbol(symbol_t symbol, int x, int y);
void write_string(const std::string &str, int x, int y);

int input();

void render_frame();

}