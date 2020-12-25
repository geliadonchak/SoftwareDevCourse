#include <string>
#include "characters.h"

namespace roguelike {
    int Character::getHp() const {
        return hp_;
    }

    void Character::setHp(int date) {
        hp_ = date;
    }

    int Character::getMaxHp() const {
        return maxHp_;
    }

    void Character::setMaxHp(int date) {
        maxHp_ = date;
    }

    int Character::getDamage() const {
        return damage_;
    }

    void Character::setDamage(int date) {
        damage_ = date;
    }

    char Character::getSymbol() const {
        return symbol_;
    }

    void Character::setSymbol(char date) {
        symbol_ = date;
    }

    std::pair<int, int> Character::getPosition() const {
        return position_;
    }

    bool Character::isDead() const {
        return hp_ <= 0;
    }

    void Character::move(int dx, int dy) {
        setPosition(getPosition().first + dx, getPosition().second + dy);
    }

    void Character::hurt(int value) {
        hp_ -= value;
    }

    void Character::setPosition(int x, int y) {
        position_.first = x;
        position_.second = y;
    }

    void initFromConfig(Character &crt, const std::string &crt_type) {
        //TODO
    }

    Knight::Knight(int x, int y) {
        position_ = {x, y};
        initFromConfig(*this, "Knight");
    }

    Knight::Knight(std::pair<int, int> position) : Knight(position.first, position.second) {}

    Princess::Princess(int x, int y) {
        position_ = {x, y};
        initFromConfig(*this, "Princess");
    }

    Princess::Princess(std::pair<int, int> position) : Princess(position.first, position.second) {}

    Wall::Wall(int x, int y) {
        position_ = {x, y};
        initFromConfig(*this, "Wall");
    }

    Wall::Wall(std::pair<int, int> position) : Wall(position.first, position.second) {}

    Zombie::Zombie(int x, int y) {
        position_ = {x, y};
        initFromConfig(*this, "Zombie");
    }

    Zombie::Zombie(std::pair<int, int> position) : Zombie(position.first, position.second) {}

    Dragon::Dragon(int x, int y) {
        position_ = {x, y};
        initFromConfig(*this, "Dragon");
    }

    Dragon::Dragon(std::pair<int, int> position) : Dragon(position.first, position.second) {}
}