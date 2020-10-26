#include "ConsoleView.h"

void ConsoleView::showTxt(string txt) {
    cout << txt << endl;
}

void ConsoleView::showArtist(Artist *artist) {
    cout << "\t\t" << artist->getNickName() << endl
         << "\t\t" << artist->getName() << " " << artist->getSurname() << endl;
}

void ConsoleView::showActor(Actor *actor) {
    cout << "\t" << actor->getRole() << endl
         << "\t" << actor->getName() << " " << actor->getSurname() << endl;
}

void ConsoleView::showSong(Song *song) {
    cout << "\t" << song->getTitle() << endl
         << "\t" << song->getLength() << endl;
    for (auto artist : song->getArtists()) {
        showArtist(artist);
    }
}

void ConsoleView::showList(Position *list) {
    cout << endl << "=========CONSOLE VIEW=========" << endl;
    while (list) {
        if (AudioCd *audioCd = dynamic_cast<AudioCd *>(list)) {
            showAudioCd(audioCd);
        } else if (AudioTape *audioTape = dynamic_cast<AudioTape *>(list)) {
            showAudioTape(audioTape);
        } else if (VideoCd *videoCd = dynamic_cast<VideoCd *>(list)) {
            showVideoCd(videoCd);
        } else if (VideoTape *videoTape = dynamic_cast<VideoTape *>(list)) {
            showVideoTape(videoTape);
        } else {
            cout << "Type Error" << endl;
        }
        list = list->nextP;
    }
    cout << "==============================" << endl;
}

void ConsoleView::showAudioCd(AudioCd *audioCd) {
    cout << audioCd->getName() << endl << audioCd->getYear() << endl
         << audioCd->getType() << endl << audioCd->getSize() << endl;

    for (auto song : audioCd->getSongs()) {
        showSong(song);
    }
}

void ConsoleView::showAudioTape(AudioTape *audioTape) {
    cout << audioTape->getName() << endl << audioTape->getYear() << endl
         << audioTape->getType() << endl << audioTape->getLength() << endl;

    for (auto song : audioTape->getSongs()) {
        showSong(song);
    }
}

void ConsoleView::showVideoCd(VideoCd *videoCd) {
    cout << videoCd->getName() << endl << videoCd->getYear() << endl
         << videoCd->getType() << endl << videoCd->getSize() << endl
         << videoCd->getGenre() << endl;

    for (auto actor : videoCd->getCast()) {
        showActor(actor);
    }
}

void ConsoleView::showVideoTape(VideoTape *videoTape) {
    cout << videoTape->getName() << endl << videoTape->getYear() << endl
         << videoTape->getType() << endl << videoTape->getLength() << endl
         << videoTape->getGenre() << endl;

    for (auto actor : videoTape->getCast()) {
        showActor(actor);
    }
}