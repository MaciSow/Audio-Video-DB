#ifndef VIDEO_AUDIODB_CONSOLEVIEW_H
#define VIDEO_AUDIODB_CONSOLEVIEW_H

#include <iostream>
#include <string>
#include "../Model/Others/Artist.h"
#include "../Model/Others/Song.h"
#include "../Model/Position.h"
#include "../Model/Audio/AudioCd.h"
#include "../Model/Audio/AudioTape.h"
#include "../Model/Video/VideoCd.h"
#include "../Model/Video/VideoTape.h"

using namespace std;

class ConsoleView {
public:
    void showArtist(Artist *artist);

    void showActor(Actor *actor);

    void showAudioCd(AudioCd *audioCd);

    void showAudioTape(AudioTape *audioTape);

    void showVideoCd(VideoCd *videoCd);

    void showVideoTape(VideoTape *videoTape);

    void showSong(Song *song);

    void showList(Position *list);

//---------------------
    vector<string> getAudioData();

    vector<string> getSongData();

    vector<string> getArtistData();
//---------------------

    void showTxt(string txt);

    vector<string> getVideoData();

    vector<string> getPersonData();
};

#endif //VIDEO_AUDIODB_CONSOLEVIEW_H