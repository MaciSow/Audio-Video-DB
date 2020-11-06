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
	Text label;
	RectangleShape frame;

	string id = "";
	ostringstream text;
	bool isSelected = false;
	float width = 250;
	float height = 40;
	int limit = (int)floor((width-20)/10);
	int fontSize = 16;
	bool isNumber = false;

	enum State {
		inactive,
		hover,
		active
	};

	void create(Vector2f position, Font& font, string label);
	void setInputState(State state);
	void inputLogic(int charTyped);
	void deleteLastChar();
	void addSlash();


public:
	Input(Vector2f position, Font& font ,string label = "", float width = 250, string id = "" );
	~Input();

	void setIsNumber();
	void setValue(string value);
	void setWidth(float width);
	void setLimit(int limit);
	string getId();
	bool isMouseOver(RenderWindow*& window);
	void checkSelection(RenderWindow*& window);
	void setSelected(bool isSelected);
	void typeOn(Event input);
	void drawTo(RenderWindow*& window);
	void clear();
	bool validate();
	string getText();
};

#endif  //LIBRARY_VIEW_INPUT_H