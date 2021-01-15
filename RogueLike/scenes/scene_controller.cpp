#include <sstream>

#include "scene_controller.h"
#include "../graphics.h"
#include "../visitors/wall_visitor.h"
#include "../visitors/attack_visitor.h"
#include "../visitors/win_condition_visitor.h"

namespace scenes {

scene_controller::scene_controller(map_size_t width, map_size_t height) :
    map_(map(width, height)) {
    hero_prev_pos_ = map_.hero()->pos();
    offset_x_ = map_.hero()->pos().x - graphics::width() / 2;
    offset_y_ = map_.hero()->pos().y - graphics::height() / 2;
    key_pressed_ = false;
    calc_offsets();
}

void scene_controller::input(int command) {
    using keys::keys_enum;

    auto &hero = map_.hero();

    keys_enum cmd = keys::keys_map.at(command);
    int x_sign = (cmd == keys_enum::ARROW_LEFT || cmd == keys_enum::THROW_LEFT ? -1 : 1);
    int y_sign = (cmd == keys_enum::ARROW_UP || cmd == keys_enum::THROW_UP ? -1 : 1);
    switch (cmd) {
        case keys_enum::ARROW_RIGHT:
        case keys_enum::ARROW_LEFT:
        case keys_enum::ARROW_DOWN:
        case keys_enum::ARROW_UP: {
            speed_t dx = x_sign * (cmd == keys_enum::ARROW_LEFT || cmd == keys_enum::ARROW_RIGHT);
            speed_t dy = y_sign * (cmd == keys_enum::ARROW_DOWN || cmd == keys_enum::ARROW_UP);
            hero->move(dx, dy);

            break;
        }
        case keys_enum::THROW_UP:
        case keys_enum::THROW_DOWN:
        case keys_enum::THROW_LEFT:
        case keys_enum::THROW_RIGHT: {
            speed_t dx = x_sign * (cmd == keys_enum::THROW_LEFT || cmd == keys_enum::THROW_RIGHT);
            speed_t dy = y_sign * (cmd == keys_enum::THROW_DOWN || cmd == keys_enum::THROW_UP);

            auto p = hero->pos();
            auto fireball = std::make_shared<characters::Fireball>(p.x, p.y, dx, dy);
            if (p.x + dx >= 0 && p.x + dx < map_.width() &&
                p.y + dy >= 0 && p.y + dy < map_.height()) {
                hero_projectiles_.push_back(fireball);
            }

            break;
        }
        default: break;
    }

    auto hero_pos = hero->pos();
    if (hero_pos.x < 0 || hero_pos.x >= map_.width() ||
        hero_pos.y < 0 || hero_pos.y >= map_.height()) {
        hero->place(hero_prev_pos_.x, hero_prev_pos_.y);
    }

    key_pressed_ = true;
}

void scene_controller::tick() {
    bool level_won = false;
    auto &characters = map_.characters();
    auto &hero = map_.hero();

     // Check if a key was pressed because projectiles should move
     // every tick and other mobs should move on each key press

    // Hero collisions
    if (key_pressed_) {
        for (auto &character : characters) {
            if (hero->pos().x == character->pos().x && hero->pos().y == character->pos().y) {
                characters::visitors::wall_visitor wall;
                hero->accept(wall, *character);
                if (wall.collided()) {
                    hero->place(hero_prev_pos_.x, hero_prev_pos_.y);
                }

                characters::visitors::attack_visitor attack;
                characters::visitors::win_condition_visitor win_condition;
                hero->accept(attack, *character);
                hero->accept(win_condition, *character);
                if (!level_won) {
                    level_won = win_condition.won();
                }
                if (!character->is_dead()) {
                    hero->place(hero_prev_pos_.x, hero_prev_pos_.y);
                }
            }
        }
    }

    // Spawn hero's projectiles there to prevent collisions with hero itself
    for (auto &projectile : hero_projectiles_) {
        map_.characters().push_back(projectile);
    }
    hero_projectiles_.clear();

    // Move mobs, collide them
    for (int i = 0; i < characters.size(); i++) {
        auto prev_pos = characters[i]->pos();

        if (key_pressed_ || characters[i]->is_projectile()) {
            characters[i]->tick(hero->pos());
            auto character_projectiles = characters[i]->projectiles();
            for (auto &projectile : character_projectiles) {
                map_.characters().push_back(projectile);
            }
            character_projectiles.clear();

            auto character_pos = characters[i]->pos();
            if (character_pos.x < 0 || character_pos.x >= map_.width() ||
                character_pos.y < 0 || character_pos.y >= map_.height()) {
                characters[i]->place(prev_pos.x, prev_pos.y);
            }
            if (character_pos.x == prev_pos.x && character_pos.y == prev_pos.y) continue;

            // Check collisions after each tick
            if (characters[i]->pos().x == hero->pos().x && characters[i]->pos().y == hero->pos().y) {
                characters::visitors::attack_visitor attack;
                characters[i]->accept(attack, *hero);
                if (!hero->is_dead()) {
                    characters[i]->place(prev_pos.x, prev_pos.y);
                }
            }

            for (int j = 0; j < characters.size(); j++) {
                if (i == j) {
                    continue;
                }

                if (characters[i]->pos().x == characters[j]->pos().x && characters[i]->pos().y == characters[j]->pos().y) {
                    characters::visitors::wall_visitor wall;
                    characters[i]->accept(wall, *characters[j]);
                    if (wall.collided()) {
                        characters[i]->place(prev_pos.x, prev_pos.y);
                    }

                    characters::visitors::attack_visitor attack;
                    characters[i]->accept(attack, *characters[j]);
                    if (!characters[j]->is_dead()) {
                        characters[i]->place(prev_pos.x, prev_pos.y);
                    }
                }
            }
        }
    }

    // Clean up dead heroes
    for (auto it = characters.begin(); it != characters.end(); it++) {
        if (!(*it)->is_dead()) {
            continue;
        }

        characters.erase(it--);
    }

    if (hero->is_dead()) {
        finished_ = true;
    }

    if (level_won) {
        auto hero_hp = hero->hp();
        map_.regenerate();
        hero->hp(hero_hp);
    }

    hero_prev_pos_ = hero->pos();
    calc_offsets();
    key_pressed_ = false;
}

void scene_controller::render() {
    using namespace graphics;

    auto &map = map_;
    auto &hero = map.hero();
    auto &characters = map.characters();
    calc_offsets();

    auto y_start = offset_y_;
    auto y_end = offset_y_ + graphics::height() - 1;
    auto x_start = offset_x_;
    auto x_end = offset_x_ + graphics::width();

    for (map_size_t y = 0; y < graphics::height() - 1; y++) {
        for (map_size_t x = 0; x < graphics::width(); x++) {
            graphics::write_symbol('.', x, y);
        }
    }
    for (auto &character : characters) {
        auto pos = character->pos();
        if (pos.x >= x_start && pos.x < x_end) {
            if (pos.y >= y_start && pos.y < y_end) {
                graphics::write_symbol(character->symbol(), pos.x - x_start, pos.y - y_start);
            }
        }
    }

    auto h_pos = hero->pos();
    graphics::write_symbol(hero->symbol(), h_pos.x - x_start, h_pos.y - y_start);

    std::stringstream ss;
    ss << "HP: " << hero->hp() << "/" << hero->max_hp();
    graphics::write_string(ss.str(), 0, graphics::height() - 1);
}

void scene_controller::calc_offsets() {
    const auto field_w = graphics::width();
    const auto field_h = graphics::height() - 1;
    const auto center_rect_w = field_w / 3;
    const auto center_rect_h = field_h / 3;
    const auto map_w = map_.width();
    const auto map_h = map_.height();
    const auto center_rect_x = offset_x_ + (field_w - center_rect_w) / 2;
    const auto center_rect_y = offset_y_ + (field_h - center_rect_h) / 2;

    auto hero_pos = map_.hero()->pos();

    if (hero_pos.x < center_rect_x) {
        offset_x_ -= center_rect_x - hero_pos.x;
    }
    if (hero_pos.x >= center_rect_x + center_rect_w) {
        offset_x_ += hero_pos.x - (center_rect_x + center_rect_w);
    }

    if (hero_pos.y < center_rect_y) {
        offset_y_ -= center_rect_y - hero_pos.y;
    }
    if (hero_pos.y >= center_rect_y + center_rect_h) {
        offset_y_ += hero_pos.y - (center_rect_y + center_rect_h);
    }

    if (offset_x_ + field_w > map_w) {
        offset_x_ = map_w - field_w;
    }
    if (offset_x_ < 0) {
        offset_x_ = 0;
    }

    if (offset_y_ + field_h > map_h) {
        offset_y_ = map_h - field_h;
    }
    if (offset_y_ < 0) {
        offset_y_ = 0;
    }
}

map_point_t scene_controller::offset() const {
    return map_point_t{offset_x_, offset_y_};
}

}