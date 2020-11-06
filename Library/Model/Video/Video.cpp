#include "Video.h"

Video::Video(const string &name, int year, const string &type, const string &genre, const vector<Actor *> &cast)
        : Position(name, year, type), genre(genre), cast(cast) {}

const string &Video::getGenre() const {
    return genre;
}

void Video::setGenre(const string &genre) {
    Video::genre = genre;
}

const vector<Actor *> &Video::getCast() const {
    return cast;
}

void Video::setCast(const vector<Actor *> &cast) {
    Video::cast = cast;
}

void Video::addActor(Actor*& actor) {
	cast.push_back(actor);
}

void Video::deleteActor(Actor*& actor)
{
	int counter = 0;

	for (Actor* item : cast) {
		if (item == actor) {
			cast.erase(cast.begin() + counter);
			return;
		}
		counter++;
	}
}
