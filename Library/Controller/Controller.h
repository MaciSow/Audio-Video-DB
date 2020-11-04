
#ifndef LIBRARY_CONTROLLER_CONTROLLER_H
#define LIBRARY_CONTROLLER_CONTROLLER_H
#include "iostream"
#include "vector"

using namespace std;

class Controller {
   private:
    /* data */
   public:
    Controller(/* args */);
    ~Controller();

    void log(string data);
    void getData(vector<string> data);
};

#endif  //LIBRARY_CONTROLLER_CONTROLLER_H
