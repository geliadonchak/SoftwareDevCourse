#pragma once

#include "scene.h"

class game {
  public:
    explicit game();
    void input();
    void tick();
    void draw_scene();
    bool terminated() const;

    void start();

  private:
    std::shared_ptr<scene::scene> current_scene_;
    bool terminated_;
};