#include "Controller.h"

Controller::Controller(/* args */) {
}

Controller::~Controller() {
}

void Controller::getData(vector<string> data) {
    cout << "\nReceived data:\n";
    
    for (string item : data) {
        cout << "\t" << item << endl;
    }
}

void Controller::log(string data) {
    cout << "Logger: " + data + "\n";
}
