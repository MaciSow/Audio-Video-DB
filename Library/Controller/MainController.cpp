#include <iostream>
#include "MainController.h"


MainController::MainController() {
    list = nullptr;
    //view = new ConsoleView();
}


void MainController::home() {

    File *f1 = new File();

    this->list = f1->readData("resources/Carrier.txt");
//    this->list = f1->readData("../db.yaml");


    //view->showList(list);
//    f1->saveData(this->list,"../Final.txt");
}

Position* MainController::getList()
{
    return this->list;
}

//void MainController::createElement(Type type) {
//
//    Position *element = nullptr;
//    switch (type) {
//        case 1:
//            element = createAudio(AUDIO_CD);
//            break;
//        case 2:
//            element = createAudio(AUDIO_TAPE);
//            break;
//        case 3:
//            element = createVideo(VIDEO_CD);
//            break;
//        case 4:
//            element = createVideo(VIDEO_TAPE);
//            break;
//        default:
//            break;
//
//    }
//    if (element) {
//        element->addToList(list);
//    }
//}
//
//Position *MainController::createAudio(Type type) {
//    vector<string> data = view->getAudioData();
//    vector<string> songData = view->getSongData();
//    vector<string> artistData = view->getPersonData();
//
//    Artist *artist = new Artist(artistData[0], artistData[1], artistData[2]);
//
//    vector<Artist *> artists;
//    artists.push_back(artist);
//
//    Song *song = new Song(songData[0], artists, stof(songData[1]));
//    vector<Song *> songs;
//    songs.push_back(song);
//
//    if (type == AUDIO_CD) {
//        Position *audioCd = new AudioCd(data[0], stoi(data[1]), data[2], songs, stof(data[3]));
//        return audioCd;
//    }
//    Position *audioTape = new AudioTape(data[0], stoi(data[1]), data[2], songs, stof(data[3]));
//    return audioTape;
//}
//
//Position *MainController::createVideo(Type type) {
//    vector<string> data = view->getVideoData();
//    vector<string> actorData = view->getPersonData();
//
//    Actor *actor = new Actor(actorData[0], actorData[1], actorData[2]);
//
//    vector<Actor *> actors;
//    actors.push_back(actor);
//
//    if (type == VIDEO_CD) {
//        Position *videoCd = new VideoCd(data[0], stoi(data[1]), data[2], data[3], actors, stof(data[4]));
//        return videoCd;
//    }
//    Position *videoTape = new VideoTape(data[0], stoi(data[1]), data[2], data[3], actors, stof(data[4]));
//    return videoTape;
//}
//
//void MainController::editElement(Position *&element) {
//    if (AudioCd *audioCd = dynamic_cast<AudioCd *>(element)) {
//        audioCd->update("new title", 2006, "CD", audioCd->getSongs(), audioCd->getSize());
//    } else if (AudioTape *audioTape = dynamic_cast<AudioTape *>(element)) {
//        audioTape->update("new title", 2006, "VHS", audioTape->getSongs(), 444);
//    } else if (VideoCd *videoCd = dynamic_cast<VideoCd *>(element)) {
//        videoCd->update("new title", 2006, "CD", "drama", videoCd->getCast(), videoCd->getSize());
//    } else if (VideoTape *videoTape = dynamic_cast<VideoTape *>(element)) {
//        videoTape->update("new title", 2006, "VHS", "drama", videoTape->getCast(), videoTape->getLength());
//    } else {
//        cout << "Type Error" << endl;
//    }
//}

Position *MainController::searchElementByName(Position *list, string name) {
    while(list){
        if (list->getName()== name){
            return list;
        }
        list = list->nextP;
    }
    return nullptr;
}
