#include "wall_visitor.h"

namespace characters {
namespace visitors {

bool wall_visitor::collided() const {
    return is_collided_;
}


// =================== //
// All and Characters
// =================== //

void wall_visitor::visit(Knight &a, Character &b) {
    b.accept(*this, a);
}
void wall_visitor::visit(Princess &a, Character &b) {
    b.accept(*this, a);
}
void wall_visitor::visit(Wall &a, Character &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Zombie &a, Character &b) {
    b.accept(*this, a);
}
void wall_visitor::visit(Dragon &a, Character &b) {
    b.accept(*this, a);
}
void wall_visitor::visit(AidKit &a, Character &b) {
    b.accept(*this, a);
}
void wall_visitor::visit(Fireball &a, Character &b) {
    b.accept(*this, a);
}


// =================== //
// All and Walls
// =================== //

void wall_visitor::visit(Knight &a, Wall &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Princess &a, Wall &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Zombie &a, Wall &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Dragon &a, Wall &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Fireball &a, Wall &b) {
    is_collided_ = true;
    a.hp(0);
}


void wall_visitor::visit(Wall &a, Wall &b) {
    is_collided_ = true;
}

void wall_visitor::visit(Wall &a, Knight &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Wall &a, Princess &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Wall &a, Zombie &b) {
    is_collided_ = true;
}
void wall_visitor::visit(Wall &a, Dragon &b) {
    is_collided_ = true;
}

void wall_visitor::visit(Wall &a, Fireball &b) {
    is_collided_ = true;
    b.hp(0);
}

}
}

