#include "VideoTape.h"

VideoTape::VideoTape(const string &name, int year, const string &type, const string &genre,
                     const vector<Actor *> &cast, float length)
        : Video(name, year, type, genre, cast), length(length) {}

void VideoTape::update(const string &name, int year, const string &type, const string &genre,
                       const vector<Actor *> &cast, float length) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->genre = genre;
    this->cast = cast;
    this->length = length;
}

float VideoTape::getLength() const {
    return length;
}

void VideoTape::setLength(float lenght) {
    VideoTape::length = length;
}
