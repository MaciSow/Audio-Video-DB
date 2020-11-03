#include "CreatePage.h"

CreatePage::CreatePage(Controller *&controller, RenderWindow *&window, Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    createElements();
}

CreatePage::~CreatePage() {
}

void CreatePage::textEntered(Event &event) {
    inputName->typeOn(event);
    inputSurname->typeOn(event);
}

bool CreatePage::isMouseOver() {
    bool isCursorOver = false;
    if (inputName->isMouseOver(window)) {
        isCursorOver = true;
    }

    if (inputSurname->isMouseOver(window)) {
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
    inputName->checkSelection(window);
    inputSurname->checkSelection(window);

    if (btnSave->isClick(window)) {
        saveData();
        inputName->clear();
        inputSurname->clear();
        return home;
    }

    if (btnCancel->isClick(window)) {
        inputName->clear();
        inputSurname->clear();
        return home;
    }

    return create;

}

void CreatePage::mouseRelease() {
    btnSave->release(window);
    btnCancel->release(window);
}

void CreatePage::draw() {
    inputName->drawTo(window);
    inputSurname->drawTo(window);
    btnSave->drawTo(window);
    btnCancel->drawTo(window);
}

// private methods

void CreatePage::createElements() {
    float width = (float)(window->getSize().x);
    float posx = width / 2 - 125;

    inputName = new Input({posx, 200}, font);
    inputSurname = new Input({posx, 300}, font);

    btnSave = new Button({(float)(width / 2 - 260), 400}, "OK", font);
    btnCancel = new Button({(float)(width / 2 + 10), 400}, "CANCEL", font);
    btnCancel->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void CreatePage::saveData() {
    controller->getData(inputName->getText(), inputSurname->getText());
}