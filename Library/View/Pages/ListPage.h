#ifndef LIBRARY_VIEW_LIST_PAGE_H
#define LIBRARY_VIEW_LIST_PAGE_H
#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../Elements/ListItem.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class ListPage {
   private:
    MainController*controller;
    RenderWindow *window;
    Font font;

    RectangleShape listFrame;
    vector<ListItem *> items;
    Button *btnBack;
    Position* head;

    int offset = 0;
    int length = 0;
    int limit = 5;

    bool isOpen = false;

    void createElements();
    void drawList();
    void createSeparator(float positionY);
    void fillList(float listWidth, float itemHeight);
    string getType(Position *&position);
    void setSelectedElement(int index);
    void refresh();

   public:
    ListPage(MainController*&controller, RenderWindow *&window, Font &font);
    ~ListPage();

    bool isMouseOver();
    PageName mouseClick();
    void scroll(int offset);
    void draw();
  
};

#endif  //LIBRARY_VIEW_LIST_PAGE_H