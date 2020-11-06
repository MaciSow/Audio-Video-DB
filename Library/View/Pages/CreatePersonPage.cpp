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

	if (btnSave->isMouseOver(window) && isValid()) {
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

	if (btnSave->isClick(window) && isValid()) {
		saveData();
		clear();

		if (isArtist) {
			return createSong;
		}

		if (controller->selectedActor != nullptr) {
			return songActor;
		}

		return controller->isCreating ? create : details;

	}

	if (btnCancel->isClick(window)) {
		clear();

		if (isArtist) {
			return createSong;
		}

		if (controller->selectedActor != nullptr) {
			return songActor;
		}

		return controller->isCreating ? create : details;
	}

	if (isArtist) {
		return createArtist;
	}
	else {
		return createActor;
	}
}


void CreatePersonPage::draw() {

	if (!isOpen && controller->selectedActor != nullptr) {
		fillInputs();
		isOpen = true;
	}

	for (Input* input : inputs) {
		input->drawTo(window);
	}

	if (isValid()) {
		btnSave->drawTo(window);
	}

	btnCancel->drawTo(window);
}

// private methods

void CreatePersonPage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	inputs.push_back(new Input({ center - 290, 200 }, font, "Name:", 580, "name"));;
	inputs.push_back(new Input({ center - 290, 280 }, font, "Surname:", 580, "surname"));;

	if (isArtist) {
		inputs.push_back(new Input({ center - 290, 350 }, font, "Nickname:", 580, "nickname"));;
	}
	else {
		inputs.push_back(new Input({ center - 290, 350 }, font, "Role:", 580, "role"));;
	}

	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void CreatePersonPage::fillInputs() {
	Actor* actor = controller->selectedActor;
	inputs[0]->setValue(actor->getName());
	inputs[1]->setValue(actor->getSurname());
	inputs[2]->setValue(actor->getRole());
}

void CreatePersonPage::saveData() {

	vector<string> data;
	Position* element = controller->selectedElement;

	for (Input* input : inputs) {
		data.push_back(input->getText());
	}

	if (controller->selectedActor != nullptr) {
		controller->updatePerson(data);
		return;
	}

	if (isArtist) {
		controller->addArtist(new Artist(data[0], data[1], data[2]));
	}
	else {
		controller->addActor(new Actor(data[0], data[1], data[2]));
	}
}

void CreatePersonPage::clear() {
	isOpen = false;
	for (Input* input : inputs) {
		input->clear();
	}
}

bool CreatePersonPage::isValid()
{
	bool isValid = true;

	for (Input* input : inputs) {
		if (!input->validate()) {
			isValid = false;
		}
	}

	return isValid;
}
