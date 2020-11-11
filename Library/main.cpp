#include "iostream"

#include "View/GraphicView.h"
#include "Controller/MainController.h"

using namespace std;

int main()
{
	MainController* c1 = new MainController();

	GraphicView* view = new GraphicView(c1);
	view->start();

	c1->clean();

	return 0;
}
