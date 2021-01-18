#include <stdexcept>
#include "map.h"
#include "utils/utils.h"

map::map(map_size_t width, map_size_t height) {
    width_ = width;
    height_ = height;
    regenerate();
}

map_size_t map::width() const {
    return width_;
}

map_size_t map::height() const {
    return height_;
}

std::shared_ptr<characters::Character> &map::hero() {
    return hero_;
}

characters_container_t &map::characters() {
    return characters_;
}

void map::regenerate() {
    if (width_ <= 0 || height_ <= 0) {
        throw std::logic_error("Map size must be greater than 0");
    }

    map_container_t container = generate(width_, height_);
    characters_.clear();
    hero_ = container.hero;
    characters_ = container.characters;
}

map_container_t map::generate(map_size_t width, map_size_t height) {
    using std::vector;
    typedef enum {
        floor_,
        wall_
    } map_block;

    map_container_t result;
    auto blocks = vector<vector<map_block>>(height, vector<map_block>(width, map_block::floor_));

    // Draw borders of the box
    for (map_size_t i = 0; i < width; i++) {
        blocks[0][i] = map_block::wall_;
        blocks[height-1][i] = map_block::wall_;
    }
    for (map_size_t i = 0; i < height; i++) {
        blocks[i][0] = map_block::wall_;
        blocks[i][width-1] = map_block::wall_;
    }

    // Spawn the player somewhere
    map_point_t pos_hero{}, pos_princess{};
    pos_hero.x = static_cast<map_size_t>(roguelike::rand_int(1, width - 2));
    pos_hero.y = static_cast<map_size_t>(roguelike::rand_int(1, height - 2));
    pos_princess.x = static_cast<map_size_t>(roguelike::rand_int(1, width - 2));
    pos_princess.y = static_cast<map_size_t>(roguelike::rand_int(1, height - 2));

    result.hero = std::make_shared<characters::Knight>(pos_hero);
    result.characters.push_back(std::make_shared<characters::Princess>(pos_princess));

    for (map_size_t i = 0; i < height; i++) {
        for (map_size_t j = 0; j < width; j++) {
            if (blocks[i][j] == map_block::wall_) {
                result.characters.push_back(std::make_shared<characters::Wall>(j, i));
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        map_point_t pos_zombie{};
        pos_zombie.x = static_cast<map_size_t>(roguelike::rand_int(1, width - 2));
        pos_zombie.y = static_cast<map_size_t>(roguelike::rand_int(1, height - 2));
        auto char_sel = static_cast<map_size_t>(roguelike::rand_int(1, 3));
        switch (char_sel) {
            case 1:
                result.characters.push_back(std::make_shared<characters::Zombie>(pos_zombie));
                break;
            case 2:
                result.characters.push_back(std::make_shared<characters::Dragon>(pos_zombie));
                break;
            case 3:
                result.characters.push_back(std::make_shared<characters::AidKit>(pos_zombie));
                break;
            default:
                break;
        }
    }

    return result;
}