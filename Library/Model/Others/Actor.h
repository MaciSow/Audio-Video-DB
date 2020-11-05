#ifndef VIDEO_AUDIODB_ACTOR_H
#define VIDEO_AUDIODB_ACTOR_H

#include "Person.h"

class Actor : public Person {
private:
    string role;

public:
    Actor(const string &name, const string &surname, const string &role);

    const string &getRole() const;

    void setRole(const string &role);
};

#endif //VIDEO_AUDIODB_ACTOR_H