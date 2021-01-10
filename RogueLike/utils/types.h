#pragma once

#include <cstdint>
#include <string>
#include <map>

// characters types
typedef int32_t hp_t;
typedef int32_t speed_t;
typedef u_char symbol_t;

// map types
typedef int32_t map_size_t;
struct map_point_t {
    map_size_t x, y;
};

// characters config
typedef std::map<std::string, int> config_parameters_t;
typedef std::map<std::string, config_parameters_t> config_t;