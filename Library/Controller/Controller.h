
#ifndef LIBRARY_CONTROLLER_CONTROLLER_H
#define LIBRARY_CONTROLLER_CONTROLLER_H
#include "iostream"

using namespace std;

class Controller {
   private:
    /* data */
   public:
    Controller(/* args */);
    ~Controller();

    void log(string data);
    void getData(string name, string surname);
};

#endif  //LIBRARY_CONTROLLER_CONTROLLER_H
