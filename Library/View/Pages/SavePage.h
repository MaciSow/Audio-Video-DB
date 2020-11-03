#ifndef LIBRARY_VIEW_SAVE_PAGE_H
#define LIBRARY_VIEW_SAVE_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/Controller.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class SavePage {
   private:
    Controller *controller;
    RenderWindow *window;
    Font font;

    Input *inputFileName;

    Button *btnSave;
    Button *btnCancel;

    string defaultFileName = "file.txt";

    void createElements();
    void saveData();

   public:
    SavePage(Controller *&controller, RenderWindow *&window, Font &font);
    ~SavePage();

    void textEntered(Event &event);
    bool isMouseOver();
    Page mouseClick();
    void mouseRelease();
    void draw();
};

#endif  LIBRARY_VIEW_SAVE_PAGE_H