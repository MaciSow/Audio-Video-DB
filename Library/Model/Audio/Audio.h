#ifndef VIDEO_AUDIODB_AUDIO_H
#define VIDEO_AUDIODB_AUDIO_H

#include "../Position.h"
#include "../Others/Song.h"

class Audio : public Position {
protected:
    vector<Song *> songs;
public:
    Audio(const string &name, int year, const string &type, const vector<Song *> &songs);

    const vector<Song *> &getSongs() const;

    void setSongs(const vector<Song *> &songs);
};

#endif //VIDEO_AUDIODB_AUDIO_H