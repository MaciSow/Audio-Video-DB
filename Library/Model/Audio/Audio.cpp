#include "Audio.h"

Audio::Audio(const string &name, int year, const string &type, const vector<Song *> &songs)
        : Position(name, year, type), songs(songs) {}

const vector<Song *> &Audio::getSongs() const {
    return songs;
}

void Audio::setSongs(const vector<Song *> &songs) {
    Audio::songs = songs;
}
