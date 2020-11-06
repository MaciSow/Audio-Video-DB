#ifndef LIBRARY_VIEW_CREATE_PERSON_PAGE_H
#define LIBRARY_VIEW_CREATE_PERSON_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class CreatePersonPage{
	MainController* controller;
	RenderWindow* window;
	Font font;
	
	vector< Input*> inputs;

	Button* btnSave;
	Button* btnCancel;

	bool isArtist = true;

	bool isOpen = false;

	void createElements();
	void fillInputs();
	void saveData();
	void clear();
	bool isValid();

public:
	CreatePersonPage(MainController*& controller, RenderWindow*& window, Font& font, bool isArtist);
	~CreatePersonPage();

	void textEntered(Event& event);
	bool isMouseOver();
	PageName mouseClick();
	void draw();
};

#endif  //LIBRARY_VIEW_CREATE_PERSON_PAGE_H