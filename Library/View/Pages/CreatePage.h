#ifndef LIBRARY_VIEW_CREATE_PAGE_H
#define LIBRARY_VIEW_CREATE_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/Controller.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class CreatePage {
   private:
    Controller *controller;
    RenderWindow *window;
    Font font;

    Input *inputName;
    Input *inputSurname;

    Button *btnSave;
    Button *btnCancel;

    void createElements();
    void saveData();

   public:
    CreatePage(Controller *&controller, RenderWindow *&window, Font &font);
    ~CreatePage();

    void textEntered(Event &event);
    bool isMouseOver();
    Page mouseClick();
    void mouseRelease();
    void draw();
};

#endif  //LIBRARY_VIEW_CREATE_PAGE_H