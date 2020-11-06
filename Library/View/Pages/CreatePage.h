#ifndef LIBRARY_VIEW_CREATE_PAGE_H
#define LIBRARY_VIEW_CREATE_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class CreatePage {
private:
	MainController* controller;
	RenderWindow* window;
	Font font;

	enum Carrier {
		audio_cd,
		audio_tape,
		video_cd,
		video_tape
	};

	Carrier carrier;

	vector< Input*> inputs;
	vector<Button*> carrierChoice;

	Button* btnAddSong;
	Button* btnAddCast;
	Button* btnSave;
	Button* btnCancel;

	
	void createElements();
	void saveData();
	void reset();
	void checkCarrier();
	void changeCarrier(Button*& button);
	bool isValid();

public:
	CreatePage(MainController*& controller, RenderWindow*& window, Font& font);
	~CreatePage();

	void textEntered(Event& event);
	bool isMouseOver();
	PageName mouseClick();
	void draw();
};

#endif  //LIBRARY_VIEW_CREATE_PAGE_H