cmake_minimum_required(VERSION 3.16)
project(Video_AudioDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(Video_AudioDB main.cpp Controller/MainController.cpp Controller/MainController.h View/ConsoleView.cpp View/ConsoleView.h Model/Person.cpp Model/Person.h Model/Artist.cpp Model/Artist.h Model/Actor.cpp Model/Actor.h Model/Song.cpp Model/Song.h)