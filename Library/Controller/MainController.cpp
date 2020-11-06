#include <iostream>
#include "MainController.h"

MainController::MainController() {
	list = nullptr;
}

void MainController::home() {
	File* f1 = new File();

	this->list = f1->readData("resources/Carrier.txt");
	//    this->list = f1->readData("../db.yaml");

		//view->showList(list);
	//    f1->saveData(this->list,"../Final.txt");
}

Position* MainController::getList() {
	return this->list;
}

void MainController::setList(Position* list) {
	this->list = list;
}

void MainController::addElement(Position*& element) {
	element->addToList(list);
}

void MainController::updateElement(vector<string> data) {

	if (selectedElement == nullptr) {
		return; 
	}

	selectedElement->setName(data[0]);
	selectedElement->setYear(12);
	selectedElement->setType(data[2]);

	if (AudioCd* audioCd = dynamic_cast<AudioCd*>(selectedElement)) {
		audioCd->setSize(stof(data[3]));
	}
	else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(selectedElement)) {
		audioTape->setLength(stof(data[4]));
	}
	else if (VideoCd* videoCd = dynamic_cast<VideoCd*>(selectedElement)) {
		videoCd->setSize(stof(data[3]));
		videoCd->setGenre(data[5]);
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(selectedElement)) {
		videoTape->setLength(stof(data[4]));
		videoTape->setGenre(data[5]);
	}
}

void MainController::updatePerson(vector<string> data) {
	if (selectedActor == nullptr) {
		return;
	}

	selectedActor->setName(data[0]);
	selectedActor->setSurname(data[1]);
	selectedActor->setRole(data[2]);
}

void MainController::updateSong(vector<string> data){
	if (selectedSong == nullptr) {
		return;
	}

	selectedSong->setTitle(data[0]);
	selectedSong->setLength(stof(data[1]));
}

void MainController::addArtist(Artist* artist) {
	if (artist == nullptr) {
		return;
	}

	newArtists.push_back(artist);

	if (selectedSong != nullptr) {
		selectedSong->addArtist(artist);
	}
}

void MainController::addActor(Actor* actor) {
	if (actor == nullptr) {
		return;
	}

	if (selectedElement == nullptr) {
		newActors.push_back(actor);
		return;
	}

	if (VideoCd* videoCd = dynamic_cast<VideoCd*>(selectedElement)) {
		videoCd->addActor(actor);
	}
	else if (VideoTape* videoTape = dynamic_cast<VideoTape*>(selectedElement)) {
		videoTape->addActor(actor);;
	}
}

void MainController::addSong(Song* song) {
	if (song == nullptr) {
		return;
	}

	if (selectedElement == nullptr) {
		newSongs.push_back(song);
	}
	else {
		if (AudioCd* audioCd = dynamic_cast<AudioCd*>(selectedElement)) {
			audioCd->addSong(song);
		}
		else if (AudioTape* audioTape = dynamic_cast<AudioTape*>(selectedElement)) {
			audioTape->addSong(song);
		}
	}

	newArtists.clear();
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
		//Position *audioCd = new AudioCd(data[0], stoi(data[1]), data[2], songs, stof(data[3]));
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

Position* MainController::searchElementByName(Position* list, string name) {
	while (list) {
		if (list->getName() == name) {
			return list;
		}
		list = list->nextP;
	}
	return nullptr;
}
