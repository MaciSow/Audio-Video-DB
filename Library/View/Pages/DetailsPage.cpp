#include "DetailsPage.h"

DetailsPage::DetailsPage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;

	createElements();
}

DetailsPage::~DetailsPage() {
}

bool DetailsPage::isMouseOver() {
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

	for (auto item : items) {
		if (item->isMouseOver(window)) {
			isCursorOver = true;
		}
	}

	return isCursorOver;
}

Page DetailsPage::mouseClick() {
	if (btnBack->isClick(window)) {
		controller->selectedElement = nullptr;
		return collection;
	}

	if (btnEdit->isClick(window)) {
		return home;
	}

	if (btnDelete->isClick(window)) {
		//Position* head = controller->getList();
		//controller->selectedElement->deleteFromList(head);
		//controller->selectedElement = nullptr;

		return collection;
	}

	for (auto item : items) {
		if (item->isClick(window)) {
			if (songs.size() > 0) {
				controller->selectedSong = songs[item->getId() - 1];
			}

			if (cast.size() > 0) {
				controller->selectedActor = cast[item->getId() - 1];
			}
			return songActor;
		}
	}

	return details;
}

void DetailsPage::scroll(int offset) {
	if (offset < -1) {
		offset = -1;
	}
	else if (offset > 1) {
		offset = 1;
	}

	if (offset > 0 && this->offset == 0) {
		return;
	}

	int countItems = items.size();
	if (offset < 0 && this->offset + limit >= countItems) {
		return;
	}

	this->offset -= offset;

	drawList();
	isMouseOver();
}

void DetailsPage::draw() {
	fillList();
	//window->draw(listFrame);
	fillDetails();
	drawList();
	btnEdit->drawTo(window);
	btnDelete->drawTo(window);
	btnBack->drawTo(window);
}

// private methods

void DetailsPage::createElements() {
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

void DetailsPage::drawList() {
	int positionOffset = 0;

	for (int i = offset; i < offset + limit; i++) {
		float positionY = listFrame.getPosition().y + ((items[i]->getHeight() + 3) * positionOffset);

		items[i]->setPosition(Vector2f(listFrame.getPosition().x, positionY));
		items[i]->drawTo(window);

		if (i < offset + limit - 1) {
			createSeparator(positionY + items[i]->getHeight() + 1);
		}

		positionOffset++;
	}
}

void DetailsPage::createSeparator(float positionY) {
	RectangleShape separator({ listFrame.getSize().x, 1 });
	separator.setFillColor({ 0, 0, 0, 100 });
	separator.move(listFrame.getPosition().x, positionY);
	window->draw(separator);
}

void DetailsPage::fillList()
{
	float listWidth = (float)(window->getSize().x) - 300;
	float itemHeight = 60;
	limit = 5;
	length = 0;
	items.clear();
	songs.clear();
	cast.clear();

	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(controller->selectedElement)) {
		songs = audioCd->getSongs();
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(controller->selectedElement)) {
		songs = audioTape->getSongs();
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(controller->selectedElement)) {
		cast = videoCd->getCast();
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(controller->selectedElement)) {
		cast = videoTape->getCast();
	}



	if (songs.size() > 0)
	{
		for (Song* song : songs) {
			items.push_back(new ListItem({ listWidth, itemHeight }, song->getTitle(), to_string(song->getLength()) + " s", font, length + 1));
			length++;
		}
	}

	if (cast.size() > 0)
	{
		for (Actor* actor : cast) {
			items.push_back(new ListItem({ listWidth, itemHeight }, actor->getRole(), actor->getName() + " " + actor->getSurname(), font, length + 1));
			length++;
		}
	}

	if (limit > length) {
		limit = length;
	}

	listFrame.setSize({ listWidth, (itemHeight + 3) * limit - 3 });
}

void DetailsPage::fillDetails() {
	float posX = 150;
	Text year("", font, 22);
	Text type("", font, 22);
	Text size("", font, 22);
	Text genre("", font, 22);
	Text itemsTxt("", font, 22);

	year.setFillColor(Color::Black);
	year.setPosition({ posX,140 });

	type.setFillColor(Color::Black);
	type.setPosition({ posX,180 });

	size.setFillColor(Color::Black);
	size.setPosition({ posX + 340,180 });

	genre.setFillColor(Color::Black);
	genre.setPosition({ posX + 340,140 });

	itemsTxt.setFillColor(Color::Black);
	itemsTxt.setPosition({ posX, 220 });


	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(controller->selectedElement)) {
		year.setString("Year: " + to_string(audioCd->getYear() + 0));
		type.setString("Carrier type: " + audioCd->getType());
		size.setString("Size: " + to_string((int)audioCd->getSize()) + " MB");
		itemsTxt.setString("Songs: ");
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(controller->selectedElement)) {
		year.setString("Year: " + to_string(audioTape->getYear()));
		type.setString("Carrier type: " + audioTape->getType());
		size.setString("Length: " + to_string((int)audioTape->getLength()) + " s");
		itemsTxt.setString("Songs: ");
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(controller->selectedElement)) {
		year.setString("Year: " + to_string(videoCd->getYear()));
		genre.setString("Genre: " + videoCd->getGenre());
		type.setString("Carrier type: " + videoCd->getType());
		size.setString("Size: " + to_string((int)videoCd->getSize()) + " MB");
		itemsTxt.setString("Cast: ");
		window->draw(genre);
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(controller->selectedElement)) {
		year.setString("Year: " + to_string(videoTape->getYear()));
		genre.setString("Genre: " + videoTape->getGenre());
		type.setString("Carrier type: " + videoTape->getType());
		size.setString("Length: " + to_string((int)videoTape->getLength()) + " s");
		itemsTxt.setString("Cast: ");
		window->draw(genre);
	}

	window->draw(year);
	window->draw(type);
	window->draw(size);
	window->draw(itemsTxt);
}

string DetailsPage::getType(Position*& position)
{
	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(position)) {
		return "Audio CD";
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(position)) {
		return "Audio Tape";
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(position)) {
		return "Video CD";
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(position)) {
		return "Video Tape";
	}
	else {
		return "Unknown type";
	}
}