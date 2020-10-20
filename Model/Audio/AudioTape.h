#ifndef VIDEO_AUDIODB_AUDIOTAPE_H
#define VIDEO_AUDIODB_AUDIOTAPE_H

#include "Audio.h"

class AudioTape : public Audio {
private:
    float length;
public:
    AudioTape(const string &name, int year, const string &type, const vector<Song *> &songs, float length);

    float getLength() const;

    void setLength(float length);
};

#endif //VIDEO_AUDIODB_AUDIOTAPE_H
