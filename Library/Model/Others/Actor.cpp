#include "Actor.h"

Actor::Actor(const string &name, const string &surname, const string &role)
        : Person(name, surname), role(role) {}

const string &Actor::getRole() const {
    return role;
}

void Actor::setRole(const string &role) {
    Actor::role = role;
}
