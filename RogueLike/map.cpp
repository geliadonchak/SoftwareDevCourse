#include "map.h"

namespace roguelike {
    Map::Map() {
        width_ = 0;
        height_ = 0;
    }

    int Map::getWidth() const {
        return width_;
    }

    int Map::getHeight() const {
        return height_;
    }

    std::shared_ptr<Character> &Map::getHero() {
        return hero_;
    }

    std::vector<std::shared_ptr<Character>> &Map::getCharacters() {
        return characters_;
    }

    void Map::resize(int width, int height) {
        width_ = width;
        height_ = height;
    }

    std::shared_ptr<Character> Map::characterAtPos(int x, int y) {
        for (auto iter = characters_.begin(); iter != characters_.end(); iter++) {
            auto &chr = *iter;
            if (chr == nullptr) {
                characters_.erase(iter);
                continue;
            }
            if (chr->getPosition().first == x && chr->getPosition().second == y) {
                return chr;
            }
        }

        return nullptr;
    }
}