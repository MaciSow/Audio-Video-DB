#ifndef VIDEO_AUDIODB_VIDEO_H
#define VIDEO_AUDIODB_VIDEO_H

#include "../Position.h"
#include "../Others/Person.h"
#include "../Others/Actor.h"

class Video : public Position {
protected:
    string genre;
    vector<Actor *> cast;
public:
    Video(const string &name, int year, const string &type, const string &genre, const vector<Actor *> &cast);

    const string &getGenre() const;

    void setGenre(const string &genre);

    const vector<Actor *> &getCast() const;

    void setCast(const vector<Actor *> &cast);

    void deleteActor(Actor*& actor);
};

#endif //VIDEO_AUDIODB_VIDEO_H