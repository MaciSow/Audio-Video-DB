#include "Controller/Controller.h"
#include "View/GraphicView.h"
#include "iostream"

using namespace std;

int main() {
    Controller* controller = new Controller();
    // controller->log("Damian");

    GraphicView* view = new GraphicView(controller);
    view->start();

    return 0;
}
