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
                Position *element = nullptr;

                switch (getClassNumber(classType)) {
                    case AUDIO_CD:
                        element = readAudioCd(File, tmp);
                        break;
                    case AUDIO_TAPE:
                        element = readAudioTape(File, tmp);
                        break;
                    case VIDEO_CD:
                        element = readVideoCd(File, tmp);
                        break;
                    case VIDEO_TAPE:
                        element = readVideoTape(File, tmp);
                        break;
                    default:
                        cout << "Invalid class" << endl;
                        validClass = false;
                        break;
                }
                if (element) {
                    element->addToList(list);
//                    list->addToList2(element);
                }
            }
        }
        File.close();

        return list;
    }
}

Type File::getClassNumber(string className) {

    if (className == "AudioCd") {
        return AUDIO_CD;
    }
    if (className == "AudioTape") {
        return AUDIO_TAPE;
    }
    if (className == "VideoCd") {
        return VIDEO_CD;
    }
    if (className == "VideoTape") {
        return VIDEO_TAPE;
    }
    return ERROR;
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

string File::saveData(Position *list, string fileName) {

    if (fileName != "") {
        this->fileName = fileName;
    }

    ofstream File(fileName);
    if (File.is_open()) {
        while (list) {
            if (AudioCd *audioCd = dynamic_cast<AudioCd *>(list)) {
                printAudioCd(File, audioCd);
            } else if (AudioTape *audioTape = dynamic_cast<AudioTape *>(list)) {
                printAudioTape(File, audioTape);
            } else if (VideoCd *videoCd = dynamic_cast<VideoCd *>(list)) {
                printVideoCd(File, videoCd);
            } else if (VideoTape *videoTape = dynamic_cast<VideoTape *>(list)) {
                printVideoTape(File, videoTape);
            } else {
                cout << "Type Error" << endl;
            }
            list = list->nextP;
        }

        File.close();
    } else {
        cout << "Fail save data";
    }

    return fileName;
}

void File::printPositionData(ofstream &File, Position *position) {
    File << "  name: " << position->getName() << endl;
    File << "  year: " << position->getYear() << endl;
    File << "  type: " << position->getType() << endl;
}

void File::printSong(ofstream &File, Audio *audio) {
    File << "  songs:" << endl;

    for (auto song : audio->getSongs()) {
        File << "    - title: " << song->getTitle() << endl;
        File << "      length: " << song->getLength() << endl;
        File << "      artist: " << endl;

        for (auto artist : song->getArtists()) {
            File << "        - name: " << artist->getName() << endl;
            File << "          surname: " << artist->getSurname() << endl;
            File << "          nickname: " << artist->getNickName() << endl;
        }
    }
}

void File::printCast(ofstream &File, Video *video) {
    File << "  cast:" << endl;

    for (auto actor : video->getCast()) {
        File << "    - name: " << actor->getName() << endl;
        File << "      surname: " << actor->getSurname() << endl;
        File << "      nickname: " << actor->getRole() << endl;
    }
}

void File::printAudioCd(ofstream &File, AudioCd *audioCd) {
    File << "- class: AudioCd\n";
    printPositionData(File, audioCd);
    File << "  size: " << audioCd->getSize() << endl;

    printSong(File, audioCd);
}

void File::printAudioTape(ofstream &File, AudioTape *audioTape) {
    File << "- class: AudioTape\n";
    printPositionData(File, audioTape);
    File << "  length: " << audioTape->getLength() << endl;

    printSong(File, audioTape);
}

void File::printVideoCd(ofstream &File, VideoCd *videoCd) {
    File << "- class: VideoCd\n";
    printPositionData(File, videoCd);
    File << "  size: " << videoCd->getSize() << endl;
    File << "  genre: " << videoCd->getGenre() << endl;

    printCast(File, videoCd);
}

void File::printVideoTape(ofstream &File, VideoTape *videoTape) {
    File << "- class: VideoTape\n";
    printPositionData(File, videoTape);
    File << "  size: " << videoTape->getLength() << endl;
    File << "  genre: " << videoTape->getGenre() << endl;

    printCast(File, videoTape);
}


