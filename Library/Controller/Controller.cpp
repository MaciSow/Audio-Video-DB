#include "Controller.h"

Controller::Controller(/* args */) {
}

Controller::~Controller() {
}

void Controller::getData(string name, string surname) {
    cout << "\nReceived data: \n\tName: " + name + "\n\tSurname: " + surname + "\n\n";
}

void Controller::log(string data) {
    cout << "Logger: " + data + "\n";
}
