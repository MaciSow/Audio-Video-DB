#include "CreatePersonPage.h"
CreatePersonPage::CreatePersonPage(MainController*& controller, RenderWindow*& window, Font& font, bool isArtist) {
	this->controller = controller;
	this->window = window;
	this->font = font;
	this->isArtist = isArtist;
	createElements();
}

CreatePersonPage::~CreatePersonPage() {
}

void CreatePersonPage::textEntered(Event& event) {
	for (Input* input : inputs) {
		input->typeOn(event);
	}
}

bool CreatePersonPage::isMouseOver() {
	bool isCursorOver = false;

	for (Input* input : inputs) {
		if (input->isMouseOver(window)) {
			isCursorOver = true;
		}
	}

	if (btnSave->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnCancel->isMouseOver(window)) {
		isCursorOver = true;
	}

	return isCursorOver;
}

Page CreatePersonPage::mouseClick() {
	for (Input* input : inputs) {
		input->checkSelection(window);
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


void CreatePersonPage::draw() {
	for (Input* input : inputs) {
		input->drawTo(window);
	}

	btnSave->drawTo(window);
	btnCancel->drawTo(window);
}

// private methods

void CreatePersonPage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	inputs.push_back(new Input({ center - 290, 200 }, font, "Name:", 580, "name"));;
	inputs.push_back(new Input({ center - 290, 270 }, font, "Surname:", 280, "surname"));;
	
	if (isArtist) {
		inputs.push_back(new Input({ center - 290, 340 }, font, "Nickname:", 580, "nickname"));;
	}
	else {
		inputs.push_back(new Input({ center - 290, 340 }, font, "Role:", 280, "role"));;
	}

	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void CreatePersonPage::saveData() {
	//controller->getData(inputName->getText(), inputYear->getText());
}