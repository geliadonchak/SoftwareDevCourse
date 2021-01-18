#pragma once

#include "map.h"
#include "graphics.h"

namespace scene {

typedef std::vector<std::shared_ptr<characters::Projectile>> projectiles_container_t;

class scene {
  public:
    scene(map_size_t width, map_size_t height);

    void input();
    void tick();
    void render();

    bool finished() const;

    map_point_t offset() const;
  private:
    map map_;
    map_point_t hero_prev_pos_{};
    map_size_t offset_x_, offset_y_;
    bool key_pressed_;
    projectiles_container_t hero_projectiles_;
    bool finished_ = false;

    void calc_offsets();
};

}