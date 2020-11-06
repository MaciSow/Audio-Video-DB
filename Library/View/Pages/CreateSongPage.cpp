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

	if (btnSave->isMouseOver(window) && isValid()) {
		isCursorOver = true;
	}

	if (btnCancel->isMouseOver(window)) {
		isCursorOver = true;
	}

	return isCursorOver;
}

PageName CreateSongPage::mouseClick() {
	for (Input* input : inputs) {
		input->checkSelection(window);
	}

	if (btnAddArtist->isClick(window)) {
		return PageName::createArtist;
	}

	if (btnSave->isClick(window) && isValid()) {
		saveData();
		clear();

		if (controller->selectedSong != nullptr) {
			return PageName::songActor;
		}


		return controller->isCreating ? PageName::create : PageName::details;
	}

	if (btnCancel->isClick(window)) {
		clear();

		if (controller->selectedSong != nullptr) {
			return PageName::songActor;
		}

		return controller->isCreating ? PageName::create : PageName::details;
	}

	return PageName::createSong;
}


void CreateSongPage::draw() {
	if (!isOpen && controller->selectedSong != nullptr) {
		fillInputs();
		isOpen = true;
	}

	for (Input* input : inputs) {
		input->drawTo(window);
	}

	btnAddArtist->drawTo(window);

	if (isValid()) {
		btnSave->drawTo(window);
	}

	btnCancel->drawTo(window);
}

// private methods

void CreateSongPage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	inputs.push_back(new Input({ center - 290, 200 }, font, "Title:", 580, "title"));;
	inputs.push_back(new Input({ center - 290, 280 }, font, "Length:", 280, "length"));;

	inputs[1]->setIsNumber();

	btnAddArtist = new Button({ (float)(center - 125), 420 }, "ADD ARTIST", font);
	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void CreateSongPage::fillInputs()
{
	Song* song = controller->selectedSong;
	inputs[0]->setValue(song->getTitle());
	inputs[1]->setValue(to_string((int)song->getLength()));
}

void CreateSongPage::saveData() {
	vector<string> data;

	for (Input* input : inputs) {
		data.push_back(input->getText());
	}

	if (controller->selectedSong != nullptr) {
		controller->updateSong(data);
		return;
	}

	controller->addSong(new Song(data[0], controller->newArtists, stof(data[1])));

}

void CreateSongPage::clear() {
	isOpen = false;
	for (Input* input : inputs) {
		input->clear();
	}


}

bool CreateSongPage::isValid()
{
	bool isValid = true;

	for (Input* input : inputs) {
		if (!input->validate()) {
			isValid = false;
		}
	}

	return isValid;
}
