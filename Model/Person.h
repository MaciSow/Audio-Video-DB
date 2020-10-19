#ifndef VIDEO_AUDIODB_PERSON_H
#define VIDEO_AUDIODB_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string &name, const string &surname);

public:
    string name;
    string surname;
};

#endif //VIDEO_AUDIODB_PERSON_H