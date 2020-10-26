#include <iostream>
#include "MainController.h"

void MainController::show() {
    ConsoleView *console = new ConsoleView;

    File *f1 = new File();

    Position *list = f1->readData("../Carrier.txt");

    console->showList(list);
}