#include "win_condition_visitor.h"

namespace characters {
namespace visitors {

bool win_condition_visitor::won() const{
    return is_won_;
}


// ==================== //
// All and Characters
// ==================== //

void win_condition_visitor::visit(Knight &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(Princess &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(Wall &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(Zombie &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(Dragon &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(AidKit &a, Character &b) {
    b.accept(*this, a);
}
void win_condition_visitor::visit(Fireball &a, Character &b) {
    b.accept(*this, a);
}


// ==================== //
// Knight and Princess
// ==================== //

void win_condition_visitor::visit(Knight &a, Princess &b) {
    if (!a.is_dead()) {
        is_won_ = true;
    }
}
void win_condition_visitor::visit(Princess &a, Knight &b) {
    if (!a.is_dead()) {
        is_won_ = true;
    }
}

}
}