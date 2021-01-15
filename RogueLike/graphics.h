#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "utils/types.h"
#include "utils/keys.h"
#include "game.h"

namespace graphics {

void init();

void clear_buffer();
void clear_screen();

void init_graphics();
void shutdown_graphics();

int width();
int height();

void write_symbol(symbol_t symbol, int x, int y);
void write_string(const std::string &str, int x, int y);

int get_input();
void input(int &key_code);

void render_frame();

void draw_state(game &state);

}