#include "VideoTape.h"

VideoTape::VideoTape(const string &name, int year, const string &type, const string &genre,
                     const vector<Actor *> &cast, float length)
        : Video(name, year, type, genre, cast), length(length) {}

float VideoTape::getLength() const {
    return length;
}

void VideoTape::setLength(float lenght) {
    VideoTape::length = length;
}
