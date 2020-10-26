#include "File.h"

Position *File::readData(string fileName) {
    this->fileName = fileName;

    ifstream File;
    File.open(fileName, ios::in);

    if (!File.is_open()) {
        cout << "Nie znaleziono pliku " << fileName << endl;
        return nullptr;
    } else {
        Position *list = nullptr;
        string tmp;
        bool validClass = true;
        getline(File, tmp);

        while (!File.eof() && validClass) {
            if (tmp.substr(0, 8) == "- class:") {
                string classType = cropValue(tmp);;

                switch (getClassNumber(classType)) {
                    case 1:
                        addToList(list, readAudioCd(File, tmp));
                        break;
                    case 2:
                        addToList(list, readAudioTape(File, tmp));
                        break;
                    case 3:
                        addToList(list, readVideoCd(File, tmp));
                        break;
                    case 4:
                        addToList(list, readVideoTape(File, tmp));
                        break;
                    default:
                        cout << "Invalid class" << endl;
                        validClass = false;
                        break;
                }
            }
        }
        File.close();

        return list;
    }
}

int File::getClassNumber(string className) {

    if (className == "AudioCd") {
        return 1;
    }
    if (className == "AudioTape") {
        return 2;
    }
    if (className == "VideoCd") {
        return 3;
    }
    if (className == "VideoTape") {
        return 4;
    }
    return 0;
}

string File::getValue(ifstream &File) {
    string txt;

    getline(File, txt);
    txt = cropValue(txt);

    return txt;
}

string File::cropValue(string line) {
    line = line.substr(line.find(':') + 2);
    if (line[line.length() - 1] == '\r') {
        line.pop_back();
    }

    return line;
}

AudioCd *File::readAudioCd(ifstream &File, string &nextLine) {
    vector<string> positionData = getPositionData(File, nextLine);

    vector<Song *> songs;
    readSongs(songs, File, nextLine);

    AudioCd *audioCd = new AudioCd(positionData[0], stoi(positionData[1]), positionData[2],
                                   songs, stof(positionData[3]));
    return audioCd;
}

AudioTape *File::readAudioTape(ifstream &File, string &nextLine) {
    vector<string> positionData = getPositionData(File, nextLine);

    vector<Song *> songs;
    readSongs(songs, File, nextLine);

    AudioTape *audioTape = new AudioTape(positionData[0], stoi(positionData[1]), positionData[2],
                                         songs, stof(positionData[3]));
    return audioTape;
}

VideoCd *File::readVideoCd(ifstream &File, string &nextLine) {
    vector<string> positionData = getPositionData(File, nextLine);
    positionData.push_back(getValue(File));

    vector<Actor *> cast;
    readCast(cast, File, nextLine);

    VideoCd *videoCd = new VideoCd(positionData[0], stoi(positionData[1]), positionData[2], positionData[4],
                                   cast, stof(positionData[3]));

    return videoCd;
}

VideoTape *File::readVideoTape(ifstream &File, string &nextLine) {
    vector<string> positionData = getPositionData(File, nextLine);
    positionData.push_back(getValue(File));

    vector<Actor *> cast;
    readCast(cast, File, nextLine);

    VideoTape *videoTape = new VideoTape(positionData[0], stoi(positionData[1]), positionData[2], positionData[4],
                                         cast, stof(positionData[3]));
    return videoTape;
}

vector<string> File::getPositionData(ifstream &File, string &nextLine) {
    vector<string> positionData;

    positionData.push_back(getValue(File));
    positionData.push_back(getValue(File));
    positionData.push_back(getValue(File));
    positionData.push_back(getValue(File));

    return positionData;
}

void File::readSongs(vector<Song *> &songs, ifstream &File, string &nextLine) {
    getline(File, nextLine);
    getline(File, nextLine);

    while (!File.eof() && nextLine[4] == '-') {
        string title = cropValue(nextLine);
        string length = getValue(File);

        getline(File, nextLine);
        getline(File, nextLine);

        vector<Artist *> artists;

        while (nextLine[8] == '-') {
            string artistName = cropValue(nextLine);
            string surname, nickName;

            surname = getValue(File);
            nickName = getValue(File);

            Artist *artist = new Artist(artistName, surname, nickName);
            artists.push_back(artist);

            getline(File, nextLine);
        }

        Song *song = new Song(title, artists, stof(length));
        songs.push_back(song);
    }
}

void File::readCast(vector<Actor *> &cast, ifstream &File, string &nextLine) {
    getline(File, nextLine);
    getline(File, nextLine);

    while (!File.eof() && nextLine[4] == '-') {
        string actorName, surname, role;

        actorName = cropValue(nextLine);
        surname = getValue(File);
        role = getValue(File);

        Actor *actor = new Actor(actorName, surname, role);
        cast.push_back(actor);

        getline(File, nextLine);
    }
}

void File::addToList(Position *&list, Position *element) {
    if (list == 0) {
        list = element;
    } else {
        Position *tmp = list;
        while (tmp->nextP) {
            tmp = tmp->nextP;
        }

        tmp->nextP = element;
        element->nextP = 0;
    }
}
