#ifndef LIBRARY_VIEW_EDIT_PAGE_H
#define LIBRARY_VIEW_EDIT_PAGE_H

#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class EditPage {
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
	Button* btnSave;
	Button* btnCancel;

	bool isOpen = false;

	void createElements();
	void fillInputs();
	void getCrrier();
	void saveData();
	void reset();
	bool isValid();

public:
	EditPage(MainController*& controller, RenderWindow*& window, Font& font);
	~EditPage();

	void textEntered(Event& event);
	bool isMouseOver();
	PageName mouseClick();
	void draw();
};

#endif  //LIBRARY_VIEW_EDIT_PAGE_H