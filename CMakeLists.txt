cmake_minimum_required(VERSION 3.16)
project(Video_AudioDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(Video_AudioDB main.cpp Controller/MainController.cpp Controller/MainController.h View/ConsoleView.cpp View/ConsoleView.h Model/Others/Person.cpp Model/Others/Person.h Model/Others/Artist.cpp Model/Others/Artist.h Model/Others/Actor.cpp Model/Others/Actor.h Model/Others/Song.cpp Model/Others/Song.h Model/Position.cpp Model/Position.h Model/Audio/Audio.cpp Model/Audio/Audio.h Model/Audio/AudioCd.cpp Model/Audio/AudioCd.h Model/Audio/AudioTape.cpp Model/Audio/AudioTape.h Model/Video/Video.cpp Model/Video/Video.h Model/Video/VideoTape.cpp Model/Video/VideoTape.h Model/Video/VideoCd.cpp Model/Video/VideoCd.h Model/Others/File.cpp Model/Others/File.h)