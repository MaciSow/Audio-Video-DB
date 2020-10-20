#ifndef VIDEO_AUDIODB_VIDEOTAPE_H
#define VIDEO_AUDIODB_VIDEOTAPE_H

#include "Video.h"

class VideoTape : public Video {
private:
    float lenght;
public:
    VideoTape(const string &name, int year, const string &type, const Person &director,
              const vector<Actor *> &cast, float lenght);

    float getLenght() const;

    void setLenght(float lenght);
};

#endif //VIDEO_AUDIODB_VIDEOTAPE_H