#ifndef VIDEO_AUDIODB_VIDEOTAPE_H
#define VIDEO_AUDIODB_VIDEOTAPE_H

#include "Video.h"

class VideoTape : public Video {
private:
    float length;
public:
    VideoTape(const string &name, int year, const string &type, const string &genre,
              const vector<Actor *> &cast, float length);

    void update(const string &name, int year, const string &type, const string &genre, const vector<Actor *> &cast,
                float length);

    float getLength() const;

    void setLength(float length);
};

#endif //VIDEO_AUDIODB_VIDEOTAPE_H