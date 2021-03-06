#pragma once

#include <string>
#include <memory>
#include <cstdint>
#include <vector>

#include "utils/types.h"

namespace characters {

class Character;
class Monster;
class Zombie;
class Dragon;
class Knight;
class Princess;

class PickupItem;
class Projectile;
class Wall;
class AidKit;
class Fireball;

namespace visitors {

class base_visitor {
  public:
    virtual void visit(Knight &, Knight &);
    virtual void visit(Princess &, Knight &);
    virtual void visit(Wall &, Knight &);
    virtual void visit(Zombie &, Knight &);
    virtual void visit(Dragon &, Knight &);
    virtual void visit(AidKit &, Knight &);
    virtual void visit(Fireball &, Knight &);

    virtual void visit(Knight &, Princess &);
    virtual void visit(Princess &, Princess &);
    virtual void visit(Wall &, Princess &);
    virtual void visit(Zombie &, Princess &);
    virtual void visit(Dragon &, Princess &);
    virtual void visit(AidKit &, Princess &);
    virtual void visit(Fireball &, Princess &);

    virtual void visit(Knight &, Wall &);
    virtual void visit(Princess &, Wall &);
    virtual void visit(Wall &, Wall &);
    virtual void visit(Zombie &, Wall &);
    virtual void visit(Dragon &, Wall &);
    virtual void visit(AidKit &, Wall &);
    virtual void visit(Fireball &, Wall &);

    virtual void visit(Knight &, Zombie &);
    virtual void visit(Princess &, Zombie &);
    virtual void visit(Wall &, Zombie &);
    virtual void visit(Zombie &, Zombie &);
    virtual void visit(Dragon &, Zombie &);
    virtual void visit(AidKit &, Zombie &);
    virtual void visit(Fireball &, Zombie &);

    virtual void visit(Knight &, Dragon &);
    virtual void visit(Princess &, Dragon &);
    virtual void visit(Wall &, Dragon &);
    virtual void visit(Zombie &, Dragon &);
    virtual void visit(Dragon &, Dragon &);
    virtual void visit(AidKit &, Dragon &);
    virtual void visit(Fireball &, Dragon &);

    virtual void visit(Knight &, AidKit &);
    virtual void visit(Princess &, AidKit &);
    virtual void visit(Wall &, AidKit &);
    virtual void visit(Zombie &, AidKit &);
    virtual void visit(Dragon &, AidKit &);
    virtual void visit(AidKit &, AidKit &);
    virtual void visit(Fireball &, AidKit &);

    virtual void visit(Knight &, Fireball &);
    virtual void visit(Princess &, Fireball &);
    virtual void visit(Wall &, Fireball &);
    virtual void visit(Zombie &, Fireball &);
    virtual void visit(Dragon &, Fireball &);
    virtual void visit(AidKit &, Fireball &);
    virtual void visit(Fireball &, Fireball &);

    virtual void visit(Knight &, Character &) = 0;
    virtual void visit(Princess &, Character &) = 0;
    virtual void visit(Wall &, Character &) = 0;
    virtual void visit(Zombie &, Character &) = 0;
    virtual void visit(Dragon &, Character &) = 0;
    virtual void visit(AidKit &, Character &) = 0;
    virtual void visit(Fireball &, Character &) = 0;
};

}

class Character {
  public:
    hp_t hp() const;
    void hp(hp_t amount);

    hp_t max_hp() const;
    void max_hp(hp_t amount);

    virtual hp_t damage() const;
    void damage(hp_t amount);

    symbol_t symbol() const;
    void symbol(symbol_t symbol);

    map_point_t pos() const;

    virtual bool is_dead() const;
    virtual bool is_projectile() const;

    std::vector<std::shared_ptr<Character>> projectiles();

    virtual void accept(visitors::base_visitor &v, Character &with) = 0;
    virtual void accept(visitors::base_visitor &v, Knight &with) = 0;
    virtual void accept(visitors::base_visitor &v, Princess &with) = 0;
    virtual void accept(visitors::base_visitor &v, Wall &with) = 0;
    virtual void accept(visitors::base_visitor &v, Zombie &with) = 0;
    virtual void accept(visitors::base_visitor &v, Dragon &with) = 0;
    virtual void accept(visitors::base_visitor &v, AidKit &with) = 0;
    virtual void accept(visitors::base_visitor &v, Fireball &with) = 0;

    virtual void tick(map_point_t hero_pos) = 0;
    virtual void move(speed_t dx, speed_t dy);
    virtual void hurt(hp_t amount);
    void place(map_size_t x, map_size_t y);

  protected:
    hp_t hp_;
    hp_t max_hp_;
    hp_t damage_;
    symbol_t symbol_;
    map_point_t position_;
    std::vector<std::shared_ptr<Character>> spawned_projectiles_;
};

class Knight : public Character {
  public:
    Knight(map_size_t x, map_size_t y);
    explicit Knight(map_point_t pos);
    void tick(map_point_t) override;

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class Princess : public Character {
  public:
    Princess(map_size_t x, map_size_t y);
    explicit Princess(map_point_t pos);
    bool is_dead() const override;
    void hurt(hp_t) override;
    void tick(map_point_t) override;

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class Wall : public Character {
  public:
    Wall(map_size_t x, map_size_t y);
    explicit Wall(map_point_t pos);
    bool is_dead() const override;
    void hurt(hp_t) override;
    void tick(map_point_t) override;

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class Monster : public Character {
  public:
    void tick(map_point_t hero_pos) override;
};

class Zombie : public Monster {
  public:
    Zombie(map_size_t x, map_size_t y);
    explicit Zombie(map_point_t pos);

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class Dragon : public Monster {
  public:
    Dragon(map_size_t x, map_size_t y);

    explicit Dragon(map_point_t pos);

    void tick(map_point_t hero_pos) override;

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class PickupItem : public Character {
  public:
    bool is_dead() const override;
    void hurt(hp_t) override;
    virtual void pick_up();
  protected:
    bool picked_up_ = false;
};

class AidKit : public PickupItem {
  public:
    AidKit(map_size_t x, map_size_t y);
    explicit AidKit(map_point_t pos);
    void tick(map_point_t) override;
    hp_t damage() const override;

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

class Projectile : public Character {
  public:
    bool is_projectile() const override;
    void tick(map_point_t) override;
    virtual void speed(map_size_t dx, map_size_t dy);
  protected:
    map_size_t speed_x_;
    map_size_t speed_y_;
};

class Fireball : public Projectile {
  public:
    Fireball(map_size_t x, map_size_t y);
    Fireball(map_size_t x, map_size_t y, map_size_t dx, map_size_t dy);
    explicit Fireball(map_point_t pos);

    void accept(visitors::base_visitor &v, Character &with) override;
    void accept(visitors::base_visitor &v, Knight &with) override;
    void accept(visitors::base_visitor &v, Princess &with) override;
    void accept(visitors::base_visitor &v, Wall &with) override;
    void accept(visitors::base_visitor &v, Zombie &with) override;
    void accept(visitors::base_visitor &v, Dragon &with) override;
    void accept(visitors::base_visitor &v, AidKit &with) override;
    void accept(visitors::base_visitor &v, Fireball &with) override;
};

}