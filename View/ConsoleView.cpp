#include "ConsoleView.h"

void ConsoleView::showTxt(string txt) {
    cout << txt << endl;
}

void ConsoleView::showArtist(Artist *artist) {
    cout << artist->nickName << endl << artist->name << " " << artist->surname;
}

void ConsoleView::showSong(Song *song) {
    cout << song->title << endl;
    for (auto artist : song->artists) {
        showArtist(artist);
    }
    cout << endl << song->length << endl;
}
