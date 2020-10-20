#include "Position.h"

Position::Position(const string &name, int year, const string &type) : name(name), year(year), type(type) {}

const string &Position::getName() const {
    return name;
}

void Position::setName(const string &name) {
    Position::name = name;
}

int Position::getYear() const {
    return year;
}

void Position::setYear(int year) {
    Position::year = year;
}

const string &Position::getType() const {
    return type;
}

void Position::setType(const string &type) {
    Position::type = type;
}
