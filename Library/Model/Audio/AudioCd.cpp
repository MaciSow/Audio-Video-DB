#include "AudioCd.h"

AudioCd::AudioCd(const string &name, int year, const string &type, const vector<Song *> &songs, float size)
        : Audio(name, year, type, songs), size(size) {}

float AudioCd::getSize() const {
    return size;
}

void AudioCd::setSize(float size) {
    AudioCd::size = size;
}

AudioCd::operator int(){
    return (int)size;
}

void AudioCd::update(const string &name, int year, const string &type, const vector<Song *> &songs, float size) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->songs = songs;
    this->size = size;
}