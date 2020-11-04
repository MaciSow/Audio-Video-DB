#ifndef LIBRARY_VIEW_CREATE_PERSON_PAGE_H
#define LIBRARY_VIEW_CREATE_PERSON_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/Controller.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class CreatePersonPage{
	Controller* controller;
	RenderWindow* window;
	Font font;
	
	vector< Input*> inputs;

	Button* btnSave;
	Button* btnCancel;

	bool isArtist = true;

	void createElements();
	void saveData();

public:
	CreatePersonPage(Controller*& controller, RenderWindow*& window, Font& font, bool isArtist);
	~CreatePersonPage();

	void textEntered(Event& event);
	bool isMouseOver();
	Page mouseClick();
	void draw();
};

#endif  //LIBRARY_VIEW_CREATE_PERSON_PAGE_H