#include "CreateSongPage.h"
CreateSongPage::CreateSongPage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;
	createElements();
}

CreateSongPage::~CreateSongPage() {
}

void CreateSongPage::textEntered(Event& event) {
	for (Input* input : inputs) {
		input->typeOn(event);
	}
}

bool CreateSongPage::isMouseOver() {
	bool isCursorOver = false;

	for (Input* input : inputs) {
		if (input->isMouseOver(window)) {
			isCursorOver = true;
		}
	}

	if (btnAddArtist->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnSave->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnCancel->isMouseOver(window)) {
		isCursorOver = true;
	}

	return isCursorOver;
}

Page CreateSongPage::mouseClick() {
	for (Input* input : inputs) {
		input->checkSelection(window);
	}

	if (btnAddArtist->isClick(window)) {

		return createArtist;
	}

	if (btnSave->isClick(window)) {
		saveData();
		for (Input* input : inputs) {
			input->clear();
		}
		return create;
	}

	if (btnCancel->isClick(window)) {
		for (Input* input : inputs) {
			input->clear();
		}
		return create;
	}

	return createSong;
}


void CreateSongPage::draw() {
	for (Input* input : inputs) {
		input->drawTo(window);
	}

	btnAddArtist->drawTo(window);
	btnSave->drawTo(window);
	btnCancel->drawTo(window);
}

// private methods

void CreateSongPage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	inputs.push_back(new Input({ center - 290, 200 }, font, "Title:", 580, "title"));;
	inputs.push_back(new Input({ center - 290, 340 }, font, "Length:", 280, "length"));;

	btnAddArtist = new Button({ (float)(center - 125), 420 }, "ADD ARTIST", font);
	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void CreateSongPage::saveData() {
	
		vector<string> data;

		for (Input* input : inputs) {
			data.push_back(input->getText());
		}


		//controller->getData(data);
	

}