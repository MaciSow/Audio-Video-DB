#ifndef VIDEO_AUDIODB_AUDIOCD_H
#define VIDEO_AUDIODB_AUDIOCD_H

#include "Audio.h"

class AudioCd : public Audio {
private:
    float size;
public:
    AudioCd(const string &name, int year, const string &type, const vector<Song *> &songs, float size);

    void update(const string &name, int year, const string &type, const vector<Song *> &songs, float size);

    float getSize() const;

    void setSize(float size);
};

#endif //VIDEO_AUDIODB_AUDIOCD_H