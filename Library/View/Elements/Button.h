#ifndef LIBRARY_VIEW_BUTTON_H
#define LIBRARY_VIEW_BUTTON_H
#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;
using namespace sf;

class Button {
   private:
    RectangleShape button;
    Text text;
    Color baseCol = {0, 0, 0, 205};
    Color hoverCol = {78, 112, 30, 205};
    Color pressedCol = hoverCol;

    float width = 250;
    float height = 50;
    int fontSize = 16;
    int id = 0;
    enum State { active,
                 hover,
                 pressed };

    void create(Vector2f position, string title, Font &font);
    void setButtonState(State state);

   public:
    Button(Vector2f position, string title, Font &font, int id = 0);
    ~Button();

    int getId();
    void setId(int id);
    void setColor(Color base, Color hover);
    void setPosition(Vector2f position);

    bool isMouseOver(RenderWindow *&window);
    bool isClick(RenderWindow *&window);
    void release(RenderWindow *&window);
    void drawTo(RenderWindow *&window);
};

#endif  //LIBRARY_VIEW_BUTTON_H