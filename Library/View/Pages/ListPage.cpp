#include "ListPage.h"

ListPage::ListPage(MainController*& controller, RenderWindow*& window, Font& font) {
	this->controller = controller;
	this->window = window;
	this->font = font;
	createElements();
}

ListPage::~ListPage() {
}

bool ListPage::isMouseOver() {
	bool isCursorOver = false;

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

Page ListPage::mouseClick() {
	if (btnBack->isClick(window)) {
		controller->selectedElement = nullptr;
		isOpen = false;
		return home;
	}

	for (auto item : items) {
		if (item->isClick(window)) {
			setSelectedElement(item->getId());
			isOpen = false;
			return details;
		}
	}

	return collection;
}


void ListPage::scroll(int offset) {
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

void ListPage::draw() {
	if (!isOpen){
		refresh();
	}

	window->draw(listFrame);
	drawList();
	btnBack->drawTo(window);
}



// private methods

void ListPage::createElements() {
	float width = (float)(window->getSize().x);
	float height = (float)(window->getSize().y);
	float centerX = width / 2 - 125;
	float listWidth = (float)(window->getSize().x) - 100;
	float itemHeight = 60;

	fillList(listWidth, itemHeight);

	listFrame.setSize({ listWidth, (itemHeight + 3) * limit - 3 });
	listFrame.setOutlineThickness(1);
	listFrame.setOutlineColor({ 0, 0, 0, 100 });
	listFrame.setFillColor({ 255, 255, 255, 200 });
	listFrame.setPosition(50, 120);

	btnBack = new Button({ centerX, height - 60 }, "BACK", font);
	btnBack->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}

void ListPage::drawList() {
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

void ListPage::createSeparator(float positionY) {
	RectangleShape separator({ listFrame.getSize().x, 1 });
	separator.setFillColor({ 0, 0, 0, 100 });
	separator.move(listFrame.getPosition().x, positionY);
	window->draw(separator);
}

void ListPage::fillList(float listWidth, float itemHeight)
{
	head = controller->getList();
	Position* tmp = head;

	while (tmp) {
		items.push_back(new ListItem({ listWidth, itemHeight }, tmp->getName(), getType(tmp), font, length + 1));
		length++;

		tmp = tmp->nextP;
	}

	if (limit > length){
		limit = length;
	}
}

string ListPage::getType(Position*& position)
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

void ListPage::setSelectedElement(int index)
{
	int counter = 1;
	Position* tmp = head;

	while (tmp) {
		if (index == counter) {
			controller->selectedElement = tmp;
			return;
		}
		counter++;
		tmp = tmp->nextP;
	}
}

void ListPage::refresh()
{
	offset = 0;
	length = 0;
	limit = 5;
	isOpen = true;
	items.clear();
	createElements();
}