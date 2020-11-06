#ifndef LIBRARY_VIEW_EXIT_PAGE_H
#define LIBRARY_VIEW_EXIT_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class  ExitPage {
   private:
    MainController*controller;
    RenderWindow *window;
    Font font;

    Text* question;
    Button *btnYes;
    Button *btnNo;

    void createElements();
    void saveData();

   public:
     ExitPage(MainController*&controller, RenderWindow *&window, Font &font);
    ~ ExitPage();


    bool isMouseOver();
    PageName mouseClick();
    void draw();
};

#endif  LIBRARY_VIEW_EXIT_PAGE_H