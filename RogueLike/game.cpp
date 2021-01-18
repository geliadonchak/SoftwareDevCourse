#include "game.h"

game::game() {
    current_scene_ = std::make_shared<scene::scene>(scene::scene(120, 120));
    terminated_ = false;
}

void game::input() {
    if (current_scene_ == nullptr) {
        terminated_ = true;
        return;
    }
    current_scene_->input();
}

void game::tick() {
    if (current_scene_ == nullptr) {
        terminated_ = true;
        return;
    }

    current_scene_->tick();
    if (current_scene_->finished()) {
        current_scene_ = current_scene_->next_scene();
    }
}

bool game::terminated() const {
    return terminated_;
}

void game::draw_scene() {
    if (current_scene_ == nullptr) {
        terminated_ = true;
        return;
    }
    current_scene_->render();
}

void game::start() {
    while (!terminated()) {
        draw_scene();
        input();
        tick();
    }
}
