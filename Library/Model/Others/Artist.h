#ifndef VIDEO_AUDIODB_ARTIST_H
#define VIDEO_AUDIODB_ARTIST_H

#include "Person.h"

class Artist : public Person {
private:
    string nickName;

public:
    Artist(const string &name, const string &surname, const string &nickName);

    const string &getNickName() const;
};


#endif //VIDEO_AUDIODB_ARTIST_H
