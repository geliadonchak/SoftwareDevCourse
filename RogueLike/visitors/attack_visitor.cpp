#include "attack_visitor.h"

namespace characters {
namespace visitors {


// =================== //
// All and Characters
// =================== //

void attack_visitor::visit(Knight &a, Character &b) {
    b.hurt(a.damage());
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(Princess &a, Character &b) {
    b.hurt(a.damage());
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(Wall &a, Character &b) {
    b.hurt(a.damage());
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(Zombie &a, Character &b) {
    b.hurt(a.damage());
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(Dragon &a, Character &b) {
    b.hurt(a.damage());
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(AidKit &a, Character &b) {
    b.hurt(a.damage());
    a.pick_up();
    is_done_ = true;
    b.accept(*this, a);
}
void attack_visitor::visit(Fireball &a, Character &b) {
    b.hurt(a.damage());
    a.hp(0);
    is_done_ = true;
    b.accept(*this, a);
}


// =================== //
// All and AidKits
// =================== //

void attack_visitor::visit(Knight &a, AidKit &b) {
    if (!a.is_dead()) {
        a.hurt(b.damage());
    }
    b.pick_up();
}
void attack_visitor::visit(Princess &a, AidKit &b) {
    if (!a.is_dead()) {
        a.hurt(b.damage());
    }
    b.pick_up();
}
void attack_visitor::visit(Zombie &a, AidKit &b) {
    if (!a.is_dead()) {
        a.hurt(b.damage());
    }
    b.pick_up();
}
void attack_visitor::visit(Dragon &a, AidKit &b) {
    if (!a.is_dead()) {
        a.hurt(b.damage());
    }
    b.pick_up();
}

void attack_visitor::visit(AidKit &a, Knight &b) {
    if (!a.is_dead()) {
        b.hurt(a.damage());
    }
    a.pick_up();
}
void attack_visitor::visit(AidKit &a, Princess &b) {
    if (!a.is_dead()) {
        b.hurt(a.damage());
    }
    a.pick_up();
}
void attack_visitor::visit(AidKit &a, Zombie &b) {
    if (!a.is_dead()) {
        b.hurt(a.damage());
    }
    a.pick_up();
}
void attack_visitor::visit(AidKit &a, Dragon &b) {
    if (!a.is_dead()) {
        b.hurt(a.damage());
    }
    a.pick_up();
}


// =================== //
// All and Fireballs
// =================== //

void attack_visitor::visit(Knight &a, Fireball &b) {
    if (!is_done_) {
        a.hurt(a.damage());
    }
    b.hp(0);
}
void attack_visitor::visit(Princess &a, Fireball &b) {
    if (!is_done_) {
        a.hurt(a.damage());
    }
    b.hp(0);
}
void attack_visitor::visit(Zombie &a, Fireball &b) {
    if (!is_done_) {
        a.hurt(a.damage());
    }
    b.hp(0);
}
void attack_visitor::visit(Dragon &a, Fireball &b) {
    if (!is_done_) {
        a.hurt(a.damage());
    }
    b.hp(0);
}
void attack_visitor::visit(AidKit &a, Fireball &b) {
    a.pick_up();
    b.hp(0);
}

void attack_visitor::visit(Fireball &a, Knight &b) {
    if (!is_done_) {
        b.hurt(a.damage());
    }
    a.hp(0);
}
void attack_visitor::visit(Fireball &a, Princess &b) {
    if (!is_done_) {
        b.hurt(a.damage());
    }
    a.hp(0);
}
void attack_visitor::visit(Fireball &a, Zombie &b) {
    if (!is_done_) {
        b.hurt(a.damage());
    }
    a.hp(0);
}
void attack_visitor::visit(Fireball &a, Dragon &b) {
    if (!is_done_) {
        b.hurt(a.damage());
    }
    a.hp(0);
}
void attack_visitor::visit(Fireball &a, AidKit &b) {
    b.pick_up();
    a.hp(0);
}
void attack_visitor::visit(Fireball &a, Fireball &b) {
    a.hp(0);
    b.hp(0);
}

}
}