#include "Video.h"

Video::Video(const string &name, int year, const string &type, const Person &director, const vector<Actor *> &cast)
        : Position(name, year, type), director(director), cast(cast) {}

const Person &Video::getDirector() const {
    return director;
}

void Video::setDirector(const Person &director) {
    Video::director = director;
}

const vector<Actor *> &Video::getCast() const {
    return cast;
}

void Video::setCast(const vector<Actor *> &cast) {
    Video::cast = cast;
}
