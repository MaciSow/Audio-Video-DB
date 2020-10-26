#ifndef VIDEO_AUDIODB_VIDEOCD_H
#define VIDEO_AUDIODB_VIDEOCD_H

#include "Video.h"

class VideoCd : public Video {
private:
    float size;
public:
    VideoCd(const string &name, int year, const string &type, const string &genre,
            const vector<Actor *> &cast, float size);

    float getSize() const;

    void setSize(float size);
};

#endif //VIDEO_AUDIODB_VIDEOCD_H