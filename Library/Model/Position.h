#ifndef VIDEO_AUDIODB_POSITION_H
#define VIDEO_AUDIODB_POSITION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Position {
protected:
    string name;
    int year;
    string type;

public:
    void addToList(Position *&list);

    void addToList2(Position *&element);

    void deleteFromList(Position *&list);

    Position *nextP;

    Position(const string &name, int year, const string &type);

    const string &getName() const;

    void setName(const string &name);

    int getYear() const;

    void setYear(int year);

    const string &getType() const;

    void setType(const string &type);

    virtual ~Position() = default;

};


#endif //VIDEO_AUDIODB_POSITION_H
