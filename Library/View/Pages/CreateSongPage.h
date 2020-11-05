#ifndef LIBRARY_VIEW_CREATE_SONG_PAGE_H
#define LIBRARY_VIEW_CREATE_SONG_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "Page.h"
#include "iostream"

using namespace std;
using namespace sf;

class CreateSongPage{
	MainController* controller;
	RenderWindow* window;
	Font font;

	vector< Input*> inputs;

	Button* btnAddArtist;
	Button* btnSave;
	Button* btnCancel;

	void createElements();
	void saveData();

public:
	CreateSongPage(MainController*& controller, RenderWindow*& window, Font& font);
	~CreateSongPage();

	void textEntered(Event& event);
	bool isMouseOver();
	Page mouseClick();
	void draw();
};

#endif  //LIBRARY_VIEW_CREATE_SONG_PAGE_H