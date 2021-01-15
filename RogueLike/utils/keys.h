#pragma once

#include <map>

namespace keys {

enum keys_enum {
    NOTHING,
    ARROW_UP,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT,
    THROW_UP,
    THROW_DOWN,
    THROW_RIGHT,
    THROW_LEFT
};

std::map <int, keys_enum> keys_map {
    {-1, NOTHING},
    {'w', ARROW_UP},
    {'a', ARROW_LEFT},
    {'s', ARROW_DOWN},
    {'d', ARROW_RIGHT},
    {'i', THROW_UP},
    {'j', THROW_LEFT},
    {'k', THROW_DOWN},
    {'l', THROW_RIGHT}
};

}