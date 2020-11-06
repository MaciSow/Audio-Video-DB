#include "Audio.h"

Audio::Audio(const string& name, int year, const string& type, const vector<Song*>& songs)
	: Position(name, year, type), songs(songs) {}

const vector<Song*>& Audio::getSongs() const {
	return songs;
}

void Audio::setSongs(const vector<Song*>& songs) {
	Audio::songs = songs;
}

void Audio::addSong(Song *&song) {
	songs.push_back(song);
}

void Audio::deleteSong(Song*& song) {
	int counter = 0;

	for (Song* item : songs) {
		if (item == song) {
			songs.erase(songs.begin() + counter);
			return;
		}
		counter++;
	}
}
