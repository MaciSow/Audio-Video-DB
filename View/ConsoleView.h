#ifndef VIDEO_AUDIODB_CONSOLEVIEW_H
#define VIDEO_AUDIODB_CONSOLEVIEW_H

#include <iostream>
#include <string>
#include "../Model/Others/Artist.h"
#include "../Model/Others/Song.h"

using namespace std;

class ConsoleView {
public:
    void showTxt(string txt);

    void showArtist(Artist* artist);

    void showSong(Song* song);
};

#endif //VIDEO_AUDIODB_CONSOLEVIEW_H