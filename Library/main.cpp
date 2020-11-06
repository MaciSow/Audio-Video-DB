#include "iostream"

#include "Controller/Controller.h"
#include "Controller/MainController.h"
#include "View/GraphicView.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	MainController* c1 = new MainController();

	GraphicView* view = new GraphicView(c1);
	view->start();

	c1->clean();

	return 0;
}
