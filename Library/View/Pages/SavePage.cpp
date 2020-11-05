#include "SavePage.h"

SavePage::SavePage(MainController*&controller, RenderWindow *&window, Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    createElements();
}

SavePage::~SavePage() {
}

void SavePage::textEntered(Event &event) {
    inputFileName->typeOn(event);
}

bool SavePage::isMouseOver() {
    bool isCursorOver = false;
    if (inputFileName->isMouseOver(window)) {
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

Page SavePage::mouseClick() {
    inputFileName->checkSelection(window);

    if (btnSave->isClick(window)) {
        saveData();
        inputFileName->clear();
        inputFileName->setValue(defaultFileName);
        return home;
    }

    if (btnCancel->isClick(window)) {
        inputFileName->clear();
        inputFileName->setValue(defaultFileName);
        return home;
    }

    return save;
}

void SavePage::draw() {
    inputFileName->drawTo(window);
    btnSave->drawTo(window);
    btnCancel->drawTo(window);
}

// private methods

void SavePage::createElements() {
    float width = (float)(window->getSize().x);
    float posx = width / 2 - 125;

    inputFileName = new Input({posx, 200}, font, "Filename:");
    inputFileName->setValue(defaultFileName);

    btnSave = new Button({(float)(width / 2 - 260), 300}, "SAVE", font);
    btnCancel = new Button({(float)(width / 2 + 10), 300}, "CANCEL", font);
    btnCancel->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void SavePage::saveData() {
    //if (inputFileName->getText() == defaultFileName) {
    //controller->log("same file");
    //return;
    //}

    //controller->log(inputFileName->getText());
    //return;
}