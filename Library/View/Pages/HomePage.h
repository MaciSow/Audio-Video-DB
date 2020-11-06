#ifndef LIBRARY_VIEW_HOME_PAGE_H
#define LIBRARY_VIEW_HOME_PAGE_H
#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class HomePage {
private:
    MainController* controller;
    RenderWindow* window;
    Font font;

    Button* btnList;
    Button* btnCreate;
    Button* btnSave;
    Button* btnExit;

    void createElements();

public:
    HomePage(MainController*& controller, RenderWindow*& window, Font& font);
    ~HomePage();

    bool isMouseOver();
    PageName mouseClick();
    void draw();
};

#endif  //LIBRARY_VIEW_HOME_PAGE_H