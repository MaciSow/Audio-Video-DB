#include "Actor.h"

Actor::Actor(const string &name, const string &surname, const string &role)
        : Person(name, surname), role(role) {}
