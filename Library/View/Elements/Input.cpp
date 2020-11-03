#include "Input.h"

Input::Input(Vector2f position, Font &font) {
    create(position, font);
}

Input::~Input() {
}

void Input::setValue(string value)
{
    string newT = "";

    for (int i = 0; i < value.length(); i++) {
        newT += value[i];
    }

    text << newT;
    input.setString(newT);   
}

void Input::setLimit(int limit) {
    this->limit = limit - 1;
}

bool Input::isMouseOver(RenderWindow *&window) {
    float mouseX = (float)(Mouse::getPosition(*window).x);
    float mouseY = (float)(Mouse::getPosition(*window).y);

    float btnPosX = frame.getPosition().x;
    float btnPosY = frame.getPosition().y;

    if (mouseX > btnPosX && mouseX < btnPosX + width &&
        mouseY > btnPosY && mouseY < btnPosY + height) {
        if (!isSelected) {
            setInputState(hover);
        }

        return true;
    }

    if (!isSelected) {
        setInputState(inactive);
    }

    return false;
}

void Input::checkSelection(RenderWindow *&window) {
    if (isMouseOver(window)) {
        if (!isSelected) {
            setSelected(true);
        }

    } else {
        setSelected(false);
    }
}

void Input::setSelected(bool isSelected) {
    this->isSelected = isSelected;

    if (isSelected) {
        setInputState(active);
    } else {
        string t = text.str();
        string newT = "";

        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }

        input.setString(newT);
        setInputState(inactive);
    }
}

void Input::drawTo(RenderWindow *&window) {
    window->draw(frame);
    window->draw(input);
}

void Input::typeOn(Event event) {
    if (isSelected) {
        int charTyped = event.text.unicode;

        if (charTyped < 128) {
            if (text.str().length() <= (int)limit) {
                inputLogic(charTyped);
            } else if (text.str().length() > (int)limit && charTyped == DELETE_KEY) {
                deleteLastChar();
            }

            if (charTyped == ENTER_KEY) {
                setSelected(false);
            }
        }
    }
}

void Input::clear() {
    text.str("");
    input.setString("");
}

string Input::getText() {
    return text.str();
}

// private methods

void Input::create(Vector2f position, Font &font) {
    float posX = position.x;
    float posY = position.y;

    input.setFont(font);
    input.setCharacterSize(fontSize);
    frame.setSize({width, height});
    frame.setOutlineThickness(1);
    frame.move(posX, posY);

    setInputState(inactive);

    float centerY = posY + (height / 2) - (fontSize / 2) - 3;

    input.setPosition({posX + 10, centerY});
}

void Input::setInputState(State state) {
    switch (state) {
        case inactive:
            frame.setFillColor({255, 255, 255, 150});
            frame.setOutlineColor({0, 0, 0, 100});
            input.setFillColor(Color::Black);
            break;
        case hover:
            frame.setFillColor({255, 255, 255, 200});
            break;
        case active:
            frame.setFillColor({255, 255, 255, 250});
            frame.setOutlineColor({0, 0, 0, 250});
            break;

        default:
            break;
    }
}

void Input::inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
        
    } else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }

    input.setString(text.str() + "_");
}

void Input::deleteLastChar() {
    string t = text.str();
    string newT = "";

    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }

    text.str("");
    text << newT;

    input.setString(text.str());
}