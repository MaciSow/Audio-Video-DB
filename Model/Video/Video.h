#ifndef VIDEO_AUDIODB_VIDEO_H
#define VIDEO_AUDIODB_VIDEO_H

#include "../Position.h"
#include "../Others/Person.h"
#include "../Others/Actor.h"

class Video : public Position {
protected:
    Person director;
    vector<Actor *> cast;
public:
    Video(const string &name, int year, const string &type, const Person &director, const vector<Actor *> &cast);

    const Person &getDirector() const;

    void setDirector(const Person &director);

    const vector<Actor *> &getCast() const;

    void setCast(const vector<Actor *> &cast);
};

#endif //VIDEO_AUDIODB_VIDEO_H