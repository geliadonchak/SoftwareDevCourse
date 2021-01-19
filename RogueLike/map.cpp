#include <stdexcept>
#include <vector>
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

bool map::is_point_empty(map_size_t x, map_size_t y)  {
    for (const auto& obj : characters_) {
        if (obj->pos().x == x && obj->pos().y == y) {
            return false;
        }
    }

    return true;
}

map_point_t map::generate_objects_pos(map_size_t width, map_size_t height) {
    map_point_t pos{};
    pos.x = static_cast<map_size_t>(roguelike::rand_int(1, width - 2));
    pos.y = static_cast<map_size_t>(roguelike::rand_int(1, height - 2));

    if (!is_point_empty(pos.x, pos.y)) {
        generate_objects_pos(width, height);
    }

    return pos;
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

    for (int i = 0; i < 15; i++) {
        map_point_t pos_object{};
        pos_object = generate_objects_pos(width, height);
        auto char_sel = static_cast<map_size_t>(roguelike::rand_int(1, 6));
        switch (char_sel) {
            case 1:
                result.characters.push_back(std::make_shared<characters::Zombie>(pos_object));
                break;
            case 2:
                result.characters.push_back(std::make_shared<characters::Dragon>(pos_object));
                break;
            case 3:
                result.characters.push_back(std::make_shared<characters::AidKit>(pos_object));
                break;
            case 4:
            case 5:
            case 6: {
                auto direction = static_cast<map_size_t>(roguelike::rand_int(0, 3));
                auto length = static_cast<map_size_t>(roguelike::rand_int(3, 15));
                result.characters.push_back(std::make_shared<characters::Wall>(pos_object));

                std::vector<std::pair<int, int>> direction_deltas{
                        {0,  1},
                        {0,  -1},
                        {1,  0},
                        {-1, 0}
                };

                map_point_t wall_point{pos_object.x, pos_object.y};

                for (int j = 0; j < length - 1; j++) {
                    wall_point.x += direction_deltas[direction].first;
                    wall_point.y += direction_deltas[direction].second;
                    if (!is_point_empty(wall_point.x, wall_point.y)) {
                        continue;
                    }
                    result.characters.push_back(std::make_shared<characters::Wall>(wall_point));
                }
                break;
            }
            default:
                break;
        }
    }

    return result;
}