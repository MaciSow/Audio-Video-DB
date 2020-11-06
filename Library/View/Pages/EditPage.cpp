#include "EditPage.h"

EditPage::EditPage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;
	createElements();
}

EditPage::~EditPage() {
}

void EditPage::textEntered(Event& event) {
	for (Input* input : inputs) {
		input->typeOn(event);
	}
}

bool EditPage::isMouseOver() {
	bool isCursorOver = false;

	for (Input* input : inputs) {
		if (input->isMouseOver(window)) {

			if (carrier < 2 && input->getId() == "genre") {
				isCursorOver = false;
			}
			else {
				isCursorOver = true;
			}
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

Page EditPage::mouseClick() {
	for (Input* input : inputs) {
		input->checkSelection(window);
	}

	if (btnSave->isClick(window) && isValid()) {
		saveData();
		reset();
		for (Input* input : inputs) {
			input->clear();
		}
		return details;
	}

	if (btnCancel->isClick(window)) {
		reset();
		for (Input* input : inputs) {
			input->clear();
		}
		return details;
	}

	return edit;
}


void EditPage::draw() {

	if (!isOpen) {
		getCrrier();
		fillInputs();

		isOpen = true;
		cout << controller->isCreating;
	}

	switch (carrier) {
	case audio_cd:
		for (Input* input : inputs) {
			if (input->getId() != "length" && input->getId() != "genre")
				input->drawTo(window);
		}
		break;
	case audio_tape:
		for (Input* input : inputs) {
			if (input->getId() != "size" && input->getId() != "genre")
				input->drawTo(window);
		}
		break;
	case video_cd:
		for (Input* input : inputs) {
			if (input->getId() != "length")
				input->drawTo(window);
		}
		break;
	case video_tape:
		for (Input* input : inputs) {
			if (input->getId() != "size")
				input->drawTo(window);
		}
		break;
	default:
		break;
	}

	if (isValid()) {
		btnSave->drawTo(window);
	}

	btnCancel->drawTo(window);
}

// private methods

void EditPage::createElements() {
	float width = (float)(window->getSize().x);
	float center = width / 2;

	inputs.push_back(new Input({ center - 290, 200 }, font, "Name:", 580, "name"));
	inputs.push_back(new Input({ center - 290, 270 }, font, "Year:", 280, "year"));
	inputs.push_back(new Input({ center + 10, 270 }, font, "Type:", 280, "type"));
	inputs.push_back(new Input({ center - 290, 340 }, font, "Size:", 280, "size"));
	inputs.push_back(new Input({ center - 290, 340 }, font, "Length:", 280, "length"));
	inputs.push_back(new Input({ center + 10, 340 }, font, "Genre:", 280, "genre"));

	inputs[3]->setIsNumber();
	inputs[4]->setIsNumber();

	btnSave = new Button({ (float)(center - 260), 500 }, "OK", font);
	btnCancel = new Button({ (float)(center + 10), 500 }, "CANCEL", font);
	btnCancel->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void EditPage::fillInputs() {
	Position* element = controller->selectedElement;

	inputs[0]->setValue(element->getName());
	inputs[1]->setValue(to_string(element->getYear()));
	inputs[2]->setValue(element->getType());

	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(element)) {
		inputs[3]->setValue(to_string((int)audioCd->getSize()));
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(element)) {
		inputs[4]->setValue(to_string((int)audioTape->getLength()));
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(element)) {
		inputs[3]->setValue(to_string((int)videoCd->getSize()));
		inputs[5]->setValue(videoCd->getGenre());
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(element)) {
		inputs[4]->setValue(to_string((int)videoTape->getLength()));
		inputs[5]->setValue(videoTape->getGenre());
	}
}

void EditPage::getCrrier() {
	Position* element = controller->selectedElement;

	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(element)) {
		carrier = audio_cd;
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(element)) {
		carrier = audio_tape;
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(element)) {
		carrier = video_cd;
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(element)) {
		carrier = video_tape;
	}
}

void EditPage::saveData() {
	vector<string> data;

	for (Input* input : inputs) {
		data.push_back(input->getText());
	}

	controller->updateElement(data);
}

void EditPage::reset() {
	isOpen = false;
}

bool EditPage::isValid()
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



