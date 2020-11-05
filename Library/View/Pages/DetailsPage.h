#ifndef LIBRARY_VIEW_DETAILS_PAGE_H
#define LIBRARY_VIEW_DETAILS_PAGE_H
#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../Elements/ListItem.h"
#include "../../Controller/MainController.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class DetailsPage {
   private:
    MainController*controller;
    RenderWindow *window;
    Font font;

    RectangleShape listFrame;
    vector<ListItem *> items;
    Button *btnEdit;
    Button *btnDelete;
    Button *btnBack;
    
    vector<Song*> songs;
    vector<Actor*> cast;

    bool isOpen = false;

    int offset = 0;
    int length = 0;
    int limit = 3;


    void drawList();
    void createSeparator(float positionY);
    void createElements();
    string getType(Position *&position);
    void refresh();

   public:
    DetailsPage(MainController*&controller, RenderWindow *&window, Font &font);
    ~DetailsPage();

    bool isMouseOver();
    Page mouseClick();
    void scroll(int offset);

    void fillList();
    void fillDetails();
    void draw();
};

#endif  //LIBRARY_VIEW_DETAILS_PAGE_H