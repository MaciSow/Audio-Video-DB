#ifndef VIDEO_AUDIODB_SONG_H
#define VIDEO_AUDIODB_SONG_H

#include <iostream>
#include <string>
#include <vector>
#include "Artist.h"

using namespace std;

class Song {
private:
    string title;
    vector<Artist *> artists;
    float length;

public:
    Song(const string &title, const vector<Artist *> &artists, float length);

    const string &getTitle() const;

    void setTitle(const string &title);

    const vector<Artist*> & getArtists() const;

    void setArtists(const vector<Artist*> & artists);

    void addArtist(Artist *& artist);

    float getLength() const;

    void setLength(float length);
};


#endif //VIDEO_AUDIODB_SONG_H
