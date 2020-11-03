#include "Button.h"

Button::Button(Vector2f position, string title, Font &font, int id) {
    this->id = id;
    create(position, title, font);
}

Button::~Button() {
}

int Button::getId() {
    return id;
}

void Button::setId(int id) {
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

    text.setPosition({centerX, centerY});
}

bool Button::isMouseOver(RenderWindow *&window) {
    float mouseX = Mouse::getPosition(*window).x;
    float mouseY = Mouse::getPosition(*window).y;

    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    if (mouseX > btnPosX && mouseX < btnPosX + width &&
        mouseY > btnPosY && mouseY < btnPosY + height) {
        setButtonState(hover);

        return true;
    }

    setButtonState(active);

    return false;
}

bool Button::isClick(RenderWindow *&window) {
    if (isMouseOver(window)) {
        setButtonState(pressed);
        return true;
    }

    return false;
}

void Button::release(RenderWindow *&window) {
    if (isMouseOver(window)) {
        setButtonState(hover);

        return;
    }

    setButtonState(active);
}

void Button::drawTo(RenderWindow *&window) {
    window->draw(button);
    window->draw(text);
}

// private methods

void Button::create(Vector2f position, string title, Font &font) {
    float posX = position.x;
    float posY = position.y;

    button.setSize({width, height});
    button.setOutlineThickness(1);
    button.move(posX, posY);

    text.setString(title);
    text.setFont(font);
    text.setCharacterSize(fontSize);

    setButtonState(active);

    float centerX = (posX + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
    float centerY = (posY + button.getGlobalBounds().height / 2) - text.getGlobalBounds().height;

    text.setPosition({centerX, centerY});
}

void Button::setButtonState(State state) {
    switch (state) {
        case active:
            button.setFillColor(baseCol);
            button.setOutlineColor(Color(0, 0, 0, 250));
            text.setFillColor(Color::White);
            break;
        case hover:
            button.setFillColor(hoverCol);
            break;
        case pressed:
            pressedCol.a = 255;
            button.setFillColor(pressedCol);
            break;
        default:
            break;
    }
}
