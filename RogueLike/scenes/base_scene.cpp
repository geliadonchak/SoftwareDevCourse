#include "base_scene.h"

bool base_scene::finished() const {
    return finished_;
}

std::shared_ptr<base_scene> base_scene::next_scene() const {
    return next_scene_;
}
