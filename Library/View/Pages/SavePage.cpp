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

PageName SavePage::mouseClick() {
    inputFileName->checkSelection(window);

    if (btnSave->isClick(window)) {
        saveData();
        clear();
        return PageName::home;
    }

    if (btnCancel->isClick(window)) {
        clear();
        return PageName::home;
    }

    return PageName::save;
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
    inputFileName->setValue(controller->getFilename());

    btnSave = new Button({(float)(width / 2 - 260), 300}, "SAVE", font);
    btnCancel = new Button({(float)(width / 2 + 10), 300}, "CANCEL", font);
    btnCancel->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void SavePage::saveData() {
    controller->save(inputFileName->getText());
}

void SavePage::clear() {
    inputFileName->clear();
    inputFileName->setValue(controller->getFilename());
}
