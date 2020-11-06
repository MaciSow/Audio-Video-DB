#ifndef VIDEO_AUDIODB_MAINCONTROLLER_H
#define VIDEO_AUDIODB_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>
//#include "../View/ConsoleView.h"
#include "../Model/Others/File.h"
#include "../Model/Position.h"

using namespace std;

class MainController {
private:
	Position* list;
	File* f1;
	string path = "resources/";
	string filename = "Carrier.txt";

	Position* searchElementByName(Position* list, string name);

public:
	Position* selectedElement = nullptr;
	Actor* selectedActor = nullptr;
	Song* selectedSong = nullptr;

	vector<Song*> newSongs;
	vector<Actor*> newActors;
	vector<Artist*> newArtists;

	bool isCreating = false;

	MainController();

	Position* getList();
	string getFilename();
	void setList(Position* list);
	void addElement(Position*& element);
	void addArtist(Artist* artist);
	void addActor(Actor* actor);
	void addSong(Song* song);
	void updateElement(vector<string> data);
	void updatePerson(vector<string> data);
	void updateSong(vector<string> data);

	void save(string filename);

	void clean();

};

#endif //VIDEO_AUDIODB_MAINCONTROLLER_H