#include <iostream>
#include "MainController.h"
#include "../View/ConsoleView.h"
#include "../Model/Person.h"
#include "../Model/Artist.h"

void MainController::show() {
    ConsoleView *console = new ConsoleView;
    console->showTxt("Hello 🐶");

//    Person *person = new Person();
//    person->name = "Bogdan";
//    person->surname = "Drugi";

    Artist *artist = new Artist("Bogdan", "Drugi", "Bogdanooo");
//    artist->name = "Bogdan";
//    artist->surname = "Drugi";
//    artist->nickName = "Bogdanooo";
    vector<Artist*> vec;
    vec.push_back(artist);
    Song *song = new Song("Lala", vec, 134);

//    console->showArtist(artist);
    console->showSong(song);
}