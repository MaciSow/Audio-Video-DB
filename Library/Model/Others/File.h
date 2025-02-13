#ifndef VIDEO_AUDIODB_FILE_H
#define VIDEO_AUDIODB_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Artist.h"
#include "Song.h"
#include "Actor.h"
#include "../Position.h"
#include "../Audio/AudioCd.h"
#include "../Audio/AudioTape.h"
#include "../Video/VideoCd.h"
#include "../Video/VideoTape.h"

using namespace std;

enum Type {
    ERROR,
    AUDIO_CD,
    AUDIO_TAPE,
    VIDEO_CD,
    VIDEO_TAPE
};


class File {
private:
    string fileName;

    Type getClassNumber(string className);

    string getValue(ifstream &File);

    string cropValue(string line);

    vector<string> getPositionData(ifstream &File, string &nextLine);

    AudioCd *readAudioCd(ifstream &File, string &nextLine);

    AudioTape *readAudioTape(ifstream &File, string &nextLine);

    VideoCd *readVideoCd(ifstream &File, string &nextLine);

    VideoTape *readVideoTape(ifstream &File, string &nextLine);

    void readSongs(vector<Song *> &songs, ifstream &File, string &nextLine);

    void readCast(vector<Actor *> &cast, ifstream &File, string &nextLine);

    void addToList(Position *&list, Position *element);

    void printAudioCd(ofstream &File, AudioCd *audioCd);

    void printAudioTape(ofstream &File, AudioTape *audioTape);

    void printVideoCd(ofstream &File, VideoCd *videoCd);

    void printVideoTape(ofstream &File, VideoTape *videoTape);

    void printPositionData(ofstream &File, Position *position);

    void printSong(ofstream &File, Audio *audio);

    void printCast(ofstream &File, Video *video);

public:
    Position *readData(string fileName);

    string saveData(Position *list, string fileName = "");

};

#endif //VIDEO_AUDIODB_FILE_H