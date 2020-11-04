#include "Button.h"

Button::Button(Vector2f position, string title, Font& font, float width, string id) {
	this->width = width;
	this->id = id;
	create(position, title, font);
}

Button::~Button() {
}

string Button::getId() {
	return id;
}

void Button::setId(string id) {
	this->id = id;
}

void Button::setColor(Color base, Color hover) {
	baseCol = base;
	hoverCol = hover;
}

void Button::setPosition(Vector2f position) {
	button.setPosition(position);

	float posX = position.x;
	float posY = position.y;

	float centerX = (posX + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
	float centerY = (posY + button.getGlobalBounds().height / 2) - text.getGlobalBounds().height;

	text.setPosition({ centerX, centerY });
}

void Button::setActive(bool isActive)
{
	this->isActive = isActive;
	setButtonState(hover);
}

bool Button::getActive(){
	return isActive;
}

bool Button::isMouseOver(RenderWindow*& window) {
	int mouseX = Mouse::getPosition(*window).x;
	int mouseY = Mouse::getPosition(*window).y;

	int btnPosX = (int)button.getPosition().x;
	int btnPosY = (int)button.getPosition().y;


	if (mouseX > btnPosX && mouseX < btnPosX + width &&
		mouseY > btnPosY && mouseY < btnPosY + height) {
		setButtonState(hover);

		return true;
	}

	if (!isActive) {
		setButtonState(normal);
		return false;
	}

	return false;
}

bool Button::isClick(RenderWindow*& window) {
	if (isMouseOver(window)) {
		setButtonState(normal);
		return true;
	}

	return false;
}


void Button::drawTo(RenderWindow*& window) {
	window->draw(button);
	window->draw(text);
}

// private methods

void Button::create(Vector2f position, string title, Font& font) {
	float posX = position.x;
	float posY = position.y;

	button.setSize({ width, height });
	button.setOutlineThickness(1);
	button.setPosition(posX, posY);

	text.setString(title);
	text.setFont(font);
	text.setCharacterSize(fontSize);

	setButtonState(normal);

	float centerX = (posX + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
	float centerY = (posY + button.getGlobalBounds().height / 2) - text.getGlobalBounds().height;

	text.setPosition({ centerX, centerY });
}

void Button::setButtonState(State state) {
	switch (state) {
	case normal:
		button.setFillColor(baseCol);
		button.setOutlineColor(Color(0, 0, 0, 250));
		text.setFillColor(Color::White);
		break;
	case hover:
		button.setFillColor(hoverCol);
		break;
	default:
		break;
	}
}
