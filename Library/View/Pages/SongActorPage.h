#ifndef LIBRARY_VIEW_SONG_ACTOR_PAGE_H
#define LIBRARY_VIEW_SONG_ACTOR_PAGE_H
#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../Elements/ListItem.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class SongActorPage {
   private:
    MainController*controller;
    RenderWindow *window;
    Font font;

    RectangleShape listFrame;
   
    Button *btnEdit;
    Button *btnDelete;
    Button *btnBack;
    
    vector<Artist*> artists;

    void drawList();
    void createSeparator(float positionY);
    void createElements();

   public:
    SongActorPage(MainController*&controller, RenderWindow *&window, Font &font);
    ~SongActorPage();

    bool isMouseOver();
    PageName mouseClick();

    void fillDetails();
    void draw();
};

#endif  //LIBRARY_VIEW_SONG_ACTOR_PAGE_H