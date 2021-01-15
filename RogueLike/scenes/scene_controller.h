#pragma once

#include "base_scene.h"

namespace scenes {

typedef std::vector<std::shared_ptr<characters::Projectile>> projectiles_container_t;

class scene_controller : public base_scene {
  public:
    scene_controller(map_size_t width, map_size_t height);

    void input(int command) override;
    void tick() override;
    void render() override;

    map_point_t offset() const;

  private:
    map map_;
    map_point_t hero_prev_pos_{};
    map_size_t offset_x_, offset_y_;
    bool key_pressed_;
    projectiles_container_t hero_projectiles_;

    void calc_offsets();
};

}
