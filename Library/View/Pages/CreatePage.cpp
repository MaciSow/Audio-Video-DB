#include "CreatePage.h"

CreatePage::CreatePage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;
	createElements();
}

CreatePage::~CreatePage() {
}

void CreatePage::textEntered(Event& event) {
	for (Input* input : inputs) {
		input->typeOn(event);
	}
}

bool CreatePage::isMouseOver() {
	bool isCursorOver = false;

	for (Input* input : inputs) {
		if (input->isMouseOver(window)) {

			if (carrier < 2 && input->getId() == "genre")
			{
				isCursorOver = false;
			}
			else {
				isCursorOver = true;
			}
		}
	}

	for (Button* button : carrierChoice) {
		if (button->isMouseOver(window)) {
			isCursorOver = true;
		}
	}

	if (btnAddSong->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnAddCast->isMouseOver(window)) {
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

PageName CreatePage::mouseClick() {
	for (Input* input : inputs) {
		input->checkSelection(window);
	}

	for (Button* button : carrierChoice) {

		if (button->isClick(window)) {
			for (Input* input : inputs) {
				input->clear();
			}
			changeCarrier(button);
			checkCarrier();
		}
	}

	if (carrier <= 1 && btnAddSong->isClick(window)) {
		return PageName::createSong;
	}

	if (carrier >= 2 && btnAddCast->isClick(window)) {
		return PageName::createActor;
	}

	if (btnSave->isClick(window) && isValid()) {
		saveData();
		reset();
		for (Input* input : inputs) {
			input->clear();
		}
		return PageName::home;
	}

	if (btnCancel->isClick(window)) {
		reset();
		for (Input* input : inputs) {

			input->clear();
		}
		return PageName::home;
	}

	return PageName::create;

}


void CreatePage::draw() {
	controller->isCreating = true;

	switch (carrier)
	{
	case audio_cd:
		for (Input* input : inputs) {
			if (input->getId() != "length" && input->getId() != "genre")
				input->drawTo(window);
		}
		btnAddSong->drawTo(window);
		break;
	case audio_tape:
		for (Input* input : inputs) {
			if (input->getId() != "size" && input->getId() != "genre")
				input->drawTo(window);
		}
		btnAddSong->drawTo(window);
		break;
	case video_cd:
		for (Input* input : inputs) {
			if (input->getId() != "length")
				input->drawTo(window);
		}

		btnAddCast->drawTo(window);
		break;
	case video_tape:
		for (Input* input : inputs) {
			if (input->getId() != "size")
				input->drawTo(window);
		}
		btnAddCast->drawTo(window);
		break;
	default:
		break;
	}

	for (Button* button : carrierChoice) {
		button->drawTo(window);
	}


	if (isValid()) {
		btnSave->drawTo(window);
	}


	btnCancel->drawTo(window);
}

// private methods

void CreatePage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	carrierChoice.push_back(new Button({ center - 290, 100 }, "AUDIO CD", font, 130, "audioCd"));
	carrierChoice.push_back(new Button({ center - 140, 100 }, "AUDIO TAPE", font, 130, "audioTape"));
	carrierChoice.push_back(new Button({ center + 10, 100 }, "VIDEO CD", font, 130, "videoCd"));
	carrierChoice.push_back(new Button({ center + 160, 100 }, "VIDEO TAPE", font, 130, "videoTape"));

	carrierChoice[0]->setActive(true);
	checkCarrier();

	inputs.push_back(new Input({ center - 290, 200 }, font, "Name:", 580, "name"));
	inputs.push_back(new Input({ center - 290, 270 }, font, "Year:", 280, "year"));
	inputs.push_back(new Input({ center + 10, 270 }, font, "Type:", 280, "type"));
	inputs.push_back(new Input({ center - 290, 340 }, font, "Size:", 280, "size"));
	inputs.push_back(new Input({ center - 290, 340 }, font, "Length:", 280, "length"));
	inputs.push_back(new Input({ center + 10, 340 }, font, "Genre:", 280, "genre"));

	inputs[3]->setIsNumber();
	inputs[4]->setIsNumber();

	btnAddSong = new Button({ (float)(center - 125), 420 }, "ADD SONG", font);
	btnAddCast = new Button({ (float)(center - 125), 420 }, "ADD CAST", font);
	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}


void CreatePage::saveData() {
	vector<string> data;

	for (Input* input : inputs) {
		data.push_back(input->getText());
	}

	Position* element;

	switch (carrier)
	{
	case audio_cd:
		element = new AudioCd(data[0], stoi(data[1]), data[2], controller->newSongs, stof(data[3]));

		break;
	case audio_tape:
		element = new AudioTape(data[0], stoi(data[1]), data[2], controller->newSongs, stof(data[4]));
		break;
	case video_cd:
		element = new VideoCd(data[0], stoi(data[1]), data[2], data[5], controller->newActors, stof(data[3]));
		break;
	case video_tape:
		element = new VideoTape(data[0], stoi(data[1]), data[2], data[5], controller->newActors, stof(data[4]));

		break;
	default:
		break;
	}

	controller->addElement(element);
}

void CreatePage::reset() {
	controller->newSongs.clear();
	controller->newActors.clear();
	controller->newArtists.clear();
	controller->isCreating = false;
}

void CreatePage::checkCarrier() {
	for (Button* button : carrierChoice) {
		if (button->getActive()) {
			if (button->getId() == "audioCd")
			{
				carrier = audio_cd;
			}

			if (button->getId() == "audioTape")
			{
				carrier = audio_tape;
			}

			if (button->getId() == "videoCd")
			{
				carrier = video_cd;
			}

			if (button->getId() == "videoTape")
			{
				carrier = video_tape;
			}
		}
	}
}

void CreatePage::changeCarrier(Button*& button) {
	for (Button* button : carrierChoice) {
		button->setActive(false);
		button->isMouseOver(window);
	}
	button->setActive(true);
}

bool CreatePage::isValid()
{
	bool isValid = true;

	if (!inputs[0]->validate()) isValid = false;
	if (!inputs[1]->validate()) isValid = false;
	if (!inputs[2]->validate()) isValid = false;

	switch (carrier)
	{
	case audio_cd:
		if (!inputs[3]->validate()) isValid = false;
		break;
	case audio_tape:
		if (!inputs[4]->validate()) isValid = false;
		break;
	case video_cd:
		if (!inputs[3]->validate()) isValid = false;
		if (!inputs[5]->validate()) isValid = false;
		break;
	case video_tape:
		if (!inputs[4]->validate()) isValid = false;
		if (!inputs[5]->validate()) isValid = false;
		break;
	default:
		break;
	}

	return isValid;
}


