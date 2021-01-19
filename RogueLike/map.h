#pragma once

#include <vector>
#include "utils/types.h"
#include "characters.h"

typedef std::vector<std::shared_ptr<characters::Character>> characters_container_t;
typedef struct {
    std::shared_ptr<characters::Character> hero;
    characters_container_t characters;
} map_container_t;

class map {
  public:
    map(map_size_t width, map_size_t height);

    map_size_t width() const;
    map_size_t height() const;
    std::shared_ptr<characters::Character> &hero();
    characters_container_t &characters();

    void regenerate();

    map_container_t generate(map_size_t width, map_size_t height);
    map_point_t generate_objects_pos(map_size_t width, map_size_t height);

  private:
    map_size_t width_;
    map_size_t height_;
    std::shared_ptr<characters::Character> hero_;
    characters_container_t characters_;

    bool is_point_empty(map_size_t x, map_size_t y);
};