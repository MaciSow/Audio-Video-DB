#ifndef VIDEO_AUDIODB_SONG_H
#define VIDEO_AUDIODB_SONG_H

#include <iostream>
#include <string>
#include <vector>
#include "Artist.h"

using namespace std;

class Song {
public:
    string title;
    vector <Artist*> artists;
    float length;

    Song(const string &title, const vector<Artist*> &artists, float length);
};


#endif //VIDEO_AUDIODB_SONG_H
