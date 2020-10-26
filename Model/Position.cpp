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

void Position::addToList(Position *&list) {
    if (list == 0) {
        list = this;
    } else {
        Position *tmp = list;
        while (tmp->nextP) {
            tmp = tmp->nextP;
        }

        tmp->nextP = this;
        this->nextP = 0;
    }
}

void Position::addToList2(Position *&element) {

    if (this == nullptr) {
//        ^element;
    }

    Position *tmp = this;

    while (this->nextP) {
        tmp = tmp->nextP;
    }

    tmp->nextP = element;
    element->nextP = nullptr;

}

void Position::deleteFromList(Position *&list) {
    if (this->nextP == 0 && this == list) {
        list = 0;
        delete this;
        return;
    }

    if (this == list) {
        list = this->nextP;
        delete this;
        return;
    }

    if (this->nextP == 0) {
        Position *tmp = list;

        while (tmp) {
            if (tmp->nextP == this) {
                tmp->nextP = 0;
                delete this;
                return;
            }
            tmp = tmp->nextP;
        }
    }

    Position *tmp = list;

    while (tmp) {
        if (tmp->nextP == this) {
            tmp->nextP = this->nextP;
            delete this;
            return;
        }
        tmp = tmp->nextP;
    }
}
