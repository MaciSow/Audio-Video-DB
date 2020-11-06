#include "SongActorPage.h"

SongActorPage::SongActorPage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;

	createElements();
}

SongActorPage::~SongActorPage() {
}

bool SongActorPage::isMouseOver() {
	bool isCursorOver = false;

	if (btnEdit->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnDelete->isMouseOver(window)) {
		isCursorOver = true;
	}

	if (btnBack->isMouseOver(window)) {
		isCursorOver = true;
	}

	return isCursorOver;
}

PageName SongActorPage::mouseClick() {
	if (btnBack->isClick(window)) {
		controller->selectedSong = nullptr;
		controller->selectedActor = nullptr;
		return PageName::details;
	}

	if (btnEdit->isClick(window)) {
		if (controller->selectedSong) {
			return PageName::createSong;
		}

		if (controller->selectedActor) {
			return PageName::createActor;
		}
	}

	if (btnDelete->isClick(window)) {
		if (controller->selectedSong)
		{
			if (AudioCd* audioCd = dynamic_cast<AudioCd*>(controller->selectedElement)) {
				audioCd->deleteSong(controller->selectedSong);
			}
			else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(controller->selectedElement)) {
				audioTape->deleteSong(controller->selectedSong);
			}
		}
		if (controller->selectedActor) {
			if (VideoCd* videoCd = dynamic_cast<VideoCd*>(controller->selectedElement)) {
				videoCd->deleteActor(controller->selectedActor);
			}
			else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(controller->selectedElement)) {
				videoTape->deleteActor(controller->selectedActor);
			}
		}

		controller->selectedSong = nullptr;
		controller->selectedActor = nullptr;
		return PageName::details;
	}

	return PageName::songActor;
}

void SongActorPage::draw() {
	if (controller->selectedSong) {
		drawList();
	}

	fillDetails();
	btnEdit->drawTo(window);
	btnDelete->drawTo(window);
	btnBack->drawTo(window);
}

// private methods

void SongActorPage::createElements() {
	float width = (float)(window->getSize().x);
	float height = (float)(window->getSize().y);
	float centerX = width / 2 - 125;

	listFrame.setSize({ 0, 0 });
	listFrame.setOutlineThickness(1);
	listFrame.setOutlineColor({ 0, 0, 0, 100 });
	listFrame.setFillColor({ 255, 255, 255, 200 });
	listFrame.move(150, 260);

	btnEdit = new Button({ width - 260, 20 }, "EDIT", font, 100);


	btnDelete = new Button({ width - 150, 20 }, "DELETE", font, 100);
	btnDelete->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });

	btnBack = new Button({ centerX, height - 60 }, "BACK", font);
	btnBack->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void SongActorPage::drawList() {
	artists.clear();
	artists = controller->selectedSong->getArtists();

	float posX = 220;
	float posY = 230;
	float offset = 30;
	int i = 1;

	for (Artist* artist : artists) {
		Text artistTxt;
		artistTxt.setFont(font);
		artistTxt.setCharacterSize(18);
		artistTxt.setFillColor(Color::Black);
		artistTxt.setPosition({ posX, posY + (offset * i++) });
		artistTxt.setString(artist->getName() + " " + artist->getSurname() + " (" + artist->getNickName() + ")");
		window->draw(artistTxt);
	}
}

void SongActorPage::createSeparator(float positionY) {
	RectangleShape separator({ listFrame.getSize().x, 1 });
	separator.setFillColor({ 0, 0, 0, 100 });
	separator.move(listFrame.getPosition().x, positionY);
	window->draw(separator);
}


void SongActorPage::fillDetails() {
	float posX = 150;

	Text line1("", font, 22);
	Text line2("", font, 22);
	Text line3("", font, 22);

	line1.setPosition({ posX,140 });
	line2.setPosition({ posX,180 });
	line3.setPosition({ posX,220 });

	line1.setFillColor(Color::Black);
	line2.setFillColor(Color::Black);
	line3.setFillColor(Color::Black);

	if (controller->selectedSong) {
		line1.setString("Title: " + controller->selectedSong->getTitle());
		line2.setString("Length: " + to_string((int)controller->selectedSong->getLength()) + " s");
		line3.setString("Artists:");
	}
	else {
		line1.setString("Role: " + controller->selectedActor->getRole());
		line2.setString("Name: " + controller->selectedActor->getName());
		line3.setString("Surname: " + controller->selectedActor->getSurname());
	}

	window->draw(line1);
	window->draw(line2);
	window->draw(line3);
}