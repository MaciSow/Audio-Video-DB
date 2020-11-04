#include "CreatePage.h"

CreatePage::CreatePage(Controller*& controller, RenderWindow*& window, Font& font) {
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

	if (btnSave->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnCancel->isMouseOver(window)) {
		isCursorOver = true;
	}

	return isCursorOver;
}

Page CreatePage::mouseClick() {
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

	
	if (carrier<=1 && btnAddSong->isClick(window)) {
		return createSong;
	}

	if (carrier >= 2 && btnAddCast->isClick(window)) {
		return createActor;
	}	
	
	if (btnSave->isClick(window)) {
		saveData();
		for (Input* input : inputs) {
			input->clear();
		}
		return home;
	}

	if (btnCancel->isClick(window)) {
		for (Input* input : inputs) {
			input->clear();
		}
		return home;
	}

	return create;

}


void CreatePage::draw() {

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
	
	btnSave->drawTo(window);
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

	inputs.push_back(new Input({ center - 290, 200 }, font, "Name:", 580, "name"));;
	inputs.push_back(new Input({ center - 290, 270 }, font, "Year:", 280, "year"));;
	inputs.push_back(new Input({ center + 10, 270 }, font, "Type:", 280, "type"));;
	inputs.push_back(new Input({ center - 290, 340 }, font, "Size:", 280, "size"));;
	inputs.push_back(new Input({ center - 290, 340 }, font, "Length:", 280, "length"));;
	inputs.push_back(new Input({ center + 10, 340 }, font, "Genre:", 280, "genre"));;

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


	controller->getData(data);
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
