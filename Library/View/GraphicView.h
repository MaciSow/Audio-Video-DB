#ifndef LIBRARY_VIEW_GRAPHIC_VIEW_H
#define LIBRARY_VIEW_GRAPHIC_VIEW_H

#include "../Controller/MainController.h"
#include "Elements/Button.h"
#include "Elements/Input.h"
#include "Pages/CreatePage.h"
#include "Pages/CreateSongPage.h"
#include "Pages/CreatePersonPage.h"
#include "Pages/HomePage.h"
#include "Pages/ListPage.h"
#include "Pages/DetailsPage.h"
#include "Pages/SongActorPage.h"
#include "Pages/Page.h"
#include "Pages/SavePage.h"
#include "Pages/ExitPage.h"

#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;
using namespace sf;

class GraphicView {
private:
	MainController* controller;
	string resourcePath = "resources/";
	RenderWindow* window;
	Font font;
	Cursor cursor;
	bool isUpdate = false;
	int width = 960;
	int height = 576;
	Page page;

	HomePage* homePage;
	ListPage* listPage;
	DetailsPage* detailsPage;
	SongActorPage* songActorPage;
	CreatePage* createPage;
	CreateSongPage* createSongPage;
	CreatePersonPage* createArtistPage;
	CreatePersonPage* createActorPage;
	SavePage* savePage;
	ExitPage* exitPage;

	void textEnteredHandle(Event& event);
	void mouseMovedHandle();
	void mouseButtonPressedHandle(Event& event);
	void mouseButtonReleasedHandle();
	void mouseWheelMovedHandle(Event& event);
	void drawPage();

	void loadFont();
	void createWindow();
	void createTitle(string title);
	void createFrame(float width, float height, float offsetY = 80);
	void createBackground();

public:



	GraphicView(MainController*& ctr);
	~GraphicView();

	void start();
};

#endif  //LIBRARY_VIEW_GRAPHIC_VIEW_H
