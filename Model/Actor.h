#ifndef VIDEO_AUDIODB_ACTOR_H
#define VIDEO_AUDIODB_ACTOR_H

#include "Person.h"

class Actor : public Person {
public:
    string role;

    Actor(const string &name, const string &surname, const string &role);
};

#endif //VIDEO_AUDIODB_ACTOR_H