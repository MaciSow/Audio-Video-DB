#include <iostream>
#include "MainController.h"
#include "../View/ConsoleView.h"

void MainController::show() {
    ConsoleView *console = new ConsoleView;
    console->showTxt("Hello 🐶");

    Artist *artist = new Artist("Bogdan", "Drugi", "Bogdanooo");

    vector<Artist *> vec;
    vec.push_back(artist);
    Song *song = new Song("Lala", vec, 134);

    console->showSong(song);
}