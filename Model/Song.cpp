#include "Song.h"

Song::Song(const string &title, const vector<Artist*> &artists, float length)
        : title(title), artists(artists), length(length) {}
