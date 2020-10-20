#include "VideoTape.h"

VideoTape::VideoTape(const string &name, int year, const string &type, const Person &director,
                     const vector<Actor *> &cast, float lenght)
        : Video(name, year, type, director, cast), lenght(lenght) {}

float VideoTape::getLenght() const {
    return lenght;
}

void VideoTape::setLenght(float lenght) {
    VideoTape::lenght = lenght;
}
