#ifndef LIBRARY_VIEW_SAVE_PAGE_H
#define LIBRARY_VIEW_SAVE_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class SavePage {
   private:
    MainController*controller;
    RenderWindow *window;
    Font font;

    Input* inputFileName;

    Button *btnSave;
    Button *btnCancel;

    void createElements();
    void saveData();
    void clear();

   public:
    SavePage(MainController*&controller, RenderWindow *&window, Font &font);
    ~SavePage();

    void textEntered(Event &event);
    bool isMouseOver();
    PageName mouseClick();
    void draw();
};

#endif  LIBRARY_VIEW_SAVE_PAGE_H