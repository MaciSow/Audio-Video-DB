#include "HomePage.h"

HomePage::HomePage(MainController*& controller, RenderWindow*& window, Font& font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    createElements();
}

HomePage::~HomePage() {
}

bool HomePage::isMouseOver() {
    bool isCursorOver = false;

    if (btnList->isMouseOver(window)) {
        isCursorOver = true;
    }

    if (btnCreate->isMouseOver(window)) {
        isCursorOver = true;
    }
    
    if (btnSave->isMouseOver(window)) {
        isCursorOver = true;
    }
    
    if (btnExit->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName HomePage::mouseClick() {
    if (btnList->isClick(window)) {
        return PageName::list;
    }

    if (btnCreate->isClick(window)) {
        return PageName::create;
    }
    
    if (btnSave->isClick(window)) {
        return PageName::save;
    }
    
    if (btnExit->isClick(window)) {
        return PageName::exitView;
    }

    return PageName::home;
}


void HomePage::draw() {
    btnList->drawTo(window);
    btnCreate->drawTo(window);
    btnSave->drawTo(window);
    btnExit->drawTo(window);
}

// private methods

void HomePage::createElements() {
    float posx = (float)(window->getSize().x / 2 - 125);
    float posY = 150;
    int offset = 80;

    btnList = new Button({ posx, posY }, "LIST", font);
    btnCreate = new Button({ posx, posY += offset }, "CREATE", font);
    btnSave = new Button({ posx, posY += offset }, "SAVE", font);
    btnExit = new Button({ posx, posY += offset }, "EXIT", font);
    btnExit->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}