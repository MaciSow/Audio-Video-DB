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
	Color baseCol = { 0, 0, 0, 205 };
	Color hoverCol = { 78, 112, 30, 205 };
	Color pressedCol = hoverCol;

	bool isActive = false;
	float width = 250;
	float height = 50;
	int fontSize = 16;
	string id = "";
	enum State {
		normal,
		hover
	};

	void create(Vector2f position, string title, Font& font);
	void setButtonState(State state);

public:
	Button(Vector2f position, string title, Font& font, float width = 250, string id = "");
	~Button();

	string getId();
	void setId(string id);
	void setColor(Color base, Color hover);
	void setPosition(Vector2f position);
	void setActive(bool isActive);
	bool getActive();
	bool isMouseOver(RenderWindow*& window);
	bool isClick(RenderWindow*& window);
	void drawTo(RenderWindow*& window);
};

#endif  //LIBRARY_VIEW_BUTTON_H