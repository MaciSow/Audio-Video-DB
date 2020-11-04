#include "ListPage.h"

ListPage::ListPage(Controller *&controller, RenderWindow *&window, Font &font) {
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
        return home;
    }

    for (auto item : items) {
        if (item->isClick(window)) {
            cout << item->getId() << endl;
        }
    }

    return collection;
}



void ListPage::scroll(int offset) {
    if (offset < -1) {
        offset = -1;
    } else if (offset > 1) {
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

    listFrame.setSize({listWidth, (itemHeight + 3) * limit - 3});
    listFrame.setOutlineThickness(1);
    listFrame.setOutlineColor({0, 0, 0, 100});
    listFrame.setFillColor({255, 255, 255, 200});
    listFrame.move(50, 120);

    for (int i = 0; i < 10; i++) {
        items.push_back(new ListItem({listWidth, itemHeight}, "Item - " + to_string(i + 1), "Subtitle for " + to_string(i + 1), font, i + 1));
    }

    btnBack = new Button({centerX, height - 60}, "BACK", font);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
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
    RectangleShape separator({listFrame.getSize().x, 1});
    separator.setFillColor({0, 0, 0, 100});
    separator.move(listFrame.getPosition().x, positionY);
    window->draw(separator);
}