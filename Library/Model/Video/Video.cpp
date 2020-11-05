#include "Video.h"

Video::Video(const string &name, int year, const string &type, const string &genre, const vector<Actor *> &cast)
        : Position(name, year, type), genre(genre), cast(cast) {}

const string &Video::getGenre() const {
    return genre;
}

void Video::setGenre(const string &genre) {
    Video::genre = genre;
}

const vector<Actor *> &Video::getCast() const {
    return cast;
}

void Video::setCast(const vector<Actor *> &cast) {
    Video::cast = cast;
}
