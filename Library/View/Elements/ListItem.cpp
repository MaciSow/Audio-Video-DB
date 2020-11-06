#include "ListItem.h"

ListItem::ListItem(Vector2f size, string title, string subtitle, Font& font, int id) {
	this->id = id;
	width = size.x;
	height = size.y;
	create(title, subtitle, font);
}

int ListItem::getId() {
	return id;
}

void ListItem::setId(int id) {
	this->id = id;
}

void ListItem::setPosition(Vector2f position) {
	listItem.setPosition(position);

	title.setPosition({ listItem.getPosition().x + 20, listItem.getPosition().y + 10 });
	subtitle.setPosition({ listItem.getPosition().x + 20, listItem.getPosition().y + height - 22 });
}


bool ListItem::isMouseOver(RenderWindow*& window) {
	int mouseX = (int)Mouse::getPosition(*window).x;
	int mouseY = (int)Mouse::getPosition(*window).y;

	int btnPosX = (int)listItem.getPosition().x;
	int btnPosY = (int)listItem.getPosition().y;

	if (mouseX > btnPosX && mouseX < btnPosX + width &&
		mouseY > btnPosY && mouseY < btnPosY + height) {
		setListItemState(hover);

		return true;
	}

	setListItemState(active);

	return false;
}

bool ListItem::isClick(RenderWindow*& window) {
	if (isMouseOver(window)) {
		setListItemState(pressed);
		return true;
	}

	return false;
}

void ListItem::release(RenderWindow*& window) {
	if (isMouseOver(window)) {
		setListItemState(hover);
		return;
	}

	setListItemState(active);
}

void ListItem::drawTo(RenderWindow*& window) {
	window->draw(listItem);
	window->draw(title);
	window->draw(subtitle);
}

// private methods

void ListItem::create(string title, string subtitle, Font& font) {
	listItem.setSize({ width, height });

	this->title.setString(title);
	this->title.setFont(font);
	this->title.setCharacterSize(titleSize);

	this->subtitle.setString(subtitle);
	this->subtitle.setFont(font);
	this->subtitle.setCharacterSize(subtitleSize);
	this->subtitle.setFillColor({ 30, 30, 30, 255 });

	setListItemState(active);
}

void ListItem::setListItemState(State state) {
	switch (state) {
	case active:
		listItem.setFillColor({ 255, 255, 255, 150 });
		title.setFillColor(Color::Black);
		break;
	case hover:
		listItem.setFillColor({ 86, 155, 240, 205 });
		break;
	case pressed:
		listItem.setFillColor({ 86, 155, 240, 255 });
		break;

	default:
		break;
	}
}

int ListItem::getHeight() {
	return (int)listItem.getSize().y;
}
