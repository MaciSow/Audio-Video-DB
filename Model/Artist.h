#ifndef VIDEO_AUDIODB_ARTIST_H
#define VIDEO_AUDIODB_ARTIST_H

#include "Person.h"

class Artist : public Person {
public:
    Artist(const string &name, const string &surname, const string &nickName);

    string nickName;
};


#endif //VIDEO_AUDIODB_ARTIST_H
