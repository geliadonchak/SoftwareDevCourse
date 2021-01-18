#pragma once

#include <string>
#include "types.h"

class Config {
  public:
    static config_t characters_;

    static void init(const std::string &filename);

    static config_parameters_t get_character_parameters(const std::string &character);
};
