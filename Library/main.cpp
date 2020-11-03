#include "iostream"

#include "Controller/Controller.h"
#include "View/GraphicView.h"

using namespace std;

int main()
{
	Controller *ctr = new Controller();

	GraphicView* view = new GraphicView(ctr);
	view->start();

	return 0;
}
