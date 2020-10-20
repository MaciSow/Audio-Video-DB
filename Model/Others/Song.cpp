#include "Song.h"

Song::Song(const string &title, const vector<Artist *> &artists, float length)
        : title(title), artists(artists), length(length) {}

const string &Song::getTitle() const {
    return title;
}

void Song::setTitle(const string &title) {
    Song::title = title;
}

const vector<Artist *> &Song::getArtists() const {
    return artists;
}

void Song::setArtists(const vector<Artist *> &artists) {
    Song::artists = artists;
}

float Song::getLength() const {
    return length;
}

void Song::setLength(float length) {
    Song::length = length;
}
