#ifndef VIDEO_AUDIODB_PERSON_H
#define VIDEO_AUDIODB_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string surname;

public:
    Person(const string &name, const string &surname);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);
};

#endif //VIDEO_AUDIODB_PERSON_H