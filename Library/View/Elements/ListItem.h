#ifndef LIBRARY_VIEW_LIST_ITEM_H
#define LIBRARY_VIEW_LIST_ITEM_H
#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;
using namespace sf;

class ListItem {
   private:
    RectangleShape listItem;
    Text title;
    Text subtitle;

    float width = 250;
    float height = 50;
    int titleSize = 16;
    int subtitleSize = 12;
    int id = 0;
    enum State { active,
                 hover,
                 pressed };

    void create(string title, string subtitle, Font &font);
    void setListItemState(State state);

   public:
    ListItem(Vector2f size, string title, string subtitle, Font &font, int id = 0);
    ~ListItem();

    int getId();
    void setId(int id);
    int getHeight();
    void setPosition(Vector2f position);

    bool isMouseOver(RenderWindow *&window);
    bool isClick(RenderWindow *&window);
    void release(RenderWindow *&window);
    void drawTo(RenderWindow *&window);
};

#endif  //LIBRARY_VIEW_LIST_ITEM_H