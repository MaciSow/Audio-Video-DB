#ifndef VIDEO_AUDIODB_MAINCONTROLLER_H
#define VIDEO_AUDIODB_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>
#include "../View/ConsoleView.h"
#include "../Model/Others/File.h"
#include "../Model/Position.h"

using namespace std;

class MainController {
private:
    Position *list;
    ConsoleView *view;

    void createElement(Type type);

    Position *createAudio(Type type);

    Position *createVideo(Type type);

    void editElement(Position *&element);

public:
    MainController();

    void home();

};

#endif //VIDEO_AUDIODB_MAINCONTROLLER_H