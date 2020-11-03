#ifndef LIBRARY_VIEW_EXIT_PAGE_H
#define LIBRARY_VIEW_EXIT_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/Controller.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class  ExitPage {
   private:
    Controller *controller;
    RenderWindow *window;
    Font font;

    Text* question;
    Button *btnYes;
    Button *btnNo;

    void createElements();
    void saveData();

   public:
     ExitPage(Controller *&controller, RenderWindow *&window, Font &font);
    ~ ExitPage();


    bool isMouseOver();
    Page mouseClick();
    void mouseRelease();
    void draw();
};

#endif  LIBRARY_VIEW_EXIT_PAGE_H