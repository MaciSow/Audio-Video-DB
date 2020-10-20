#include "ConsoleView.h"

void ConsoleView::showTxt(string txt) {
    cout << txt << endl;
}

void ConsoleView::showArtist(Artist *artist) {
    cout << artist->getNickName() << endl << artist->getName() << " " << artist->getSurname();
}

void ConsoleView::showSong(Song *song) {
    cout << song->getTitle() << endl;
    for (auto artist : song->getArtists()) {
        showArtist(artist);
    }
    cout << endl << song->getLength() << endl;
}
