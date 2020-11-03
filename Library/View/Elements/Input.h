#ifndef LIBRARY_VIEW_INPUT_H
#define LIBRARY_VIEW_INPUT_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "sstream"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;
using namespace sf;

class Input {
   private:
    Text input;
    RectangleShape frame;

    ostringstream text;
    bool isSelected = false;
    int limit = 255;
    float width = 250;
    float height = 40;
    int fontSize = 16;

    enum State { inactive,
                 hover,
                 active };

    void create(Vector2f position, Font &font);
    void setInputState(State state);
    void inputLogic(int charTyped);
    void deleteLastChar();

   public:
    Input(Vector2f position, Font &font);
    ~Input();

    void setValue(string value);
    void setLimit(int limit);
    bool isMouseOver(RenderWindow *&window);
    void checkSelection(RenderWindow *&window);
    void setSelected(bool isSelected);
    void typeOn(Event input);
    void drawTo(RenderWindow *&window);
    void clear();
    string getText();
};

#endif  //LIBRARY_VIEW_INPUT_H