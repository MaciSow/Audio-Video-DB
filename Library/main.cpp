#include "iostream"

#include "Controller/Controller.h"
#include "Controller/MainController.h"
#include "View/GraphicView.h"

using namespace std;

int main()
{
	//Controller *ctr = new Controller();



	MainController* c1 = new MainController();

	c1->home();

	GraphicView* view = new GraphicView(c1);
	view->start();

	return 0;
}
