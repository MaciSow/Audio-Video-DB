#include "AudioTape.h"

AudioTape::AudioTape(const string &name, int year, const string &type, const vector<Song *> & songs, float length) : Audio(
        name, year, type, songs), length(length) {}

float AudioTape::getLength() const {
    return length;
}

void AudioTape::setLength(float length) {
    AudioTape::length = length;
}
