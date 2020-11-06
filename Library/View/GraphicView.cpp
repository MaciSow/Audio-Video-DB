#include "GraphicView.h"

GraphicView::GraphicView(MainController*& ctr) {
	this->controller = ctr;

	createWindow();
	pageName = PageName::home;
	homePage = new HomePage(controller, window, font);
	listPage = new ListPage(controller, window, font);
	detailsPage = new DetailsPage(controller, window, font);
	songActorPage = new SongActorPage(controller, window, font);
	createPage = new CreatePage(controller, window, font);
	editPage = new EditPage(controller, window, font);
	createSongPage = new CreateSongPage(controller, window, font);
	createArtistPage = new CreatePersonPage(controller, window, font, true);
	createActorPage = new CreatePersonPage(controller, window, font, false);
	savePage = new SavePage(controller, window, font);
	exitPage = new ExitPage(controller, window, font);
}

GraphicView::~GraphicView() {}

void GraphicView::start() {
	while (window->isOpen()) {
		Event event;

		while (window->pollEvent(event)) {
			switch (event.type) {
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					window->close();
				}
				break;

			case Event::TextEntered:
				textEnteredHandle(event);
				break;

			case Event::MouseMoved:
				mouseMovedHandle();
				break;

			case Event::MouseButtonPressed:
				mouseButtonPressedHandle(event);
				break;

			case Event::MouseWheelMoved:
				mouseWheelMovedHandle(event);
				break;

			case Event::Closed:
				window->close();
				break;

			default:
				break;
			}
		}

		window->clear();
		createBackground();
		drawPage();
		window->setMouseCursor(cursor);
		window->display();

		if (pageName == PageName::exitProgram)
		{
			cleanPage();
			window->close();
		}
	}
}

void GraphicView::textEnteredHandle(Event& event) {
	switch (pageName) {
	case PageName::home:
		break;

	case PageName::create:
		createPage->textEntered(event);
		break;

	case PageName::createSong:
		createSongPage->textEntered(event);
		break;

	case PageName::createArtist:
		createArtistPage->textEntered(event);
		break;

	case PageName::createActor:
		createActorPage->textEntered(event);
		break;

	case PageName::edit:
		editPage->textEntered(event);
		break;

	case PageName::save:
		savePage->textEntered(event);
		break;

	default:
		break;
	}
}

void GraphicView::mouseMovedHandle() {
	bool isCursorChange = false;

	switch (pageName) {
	case PageName::home:
		if (homePage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::list:
		if (listPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::details:
		if (detailsPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::songActor:
		if (songActorPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::create:
		if (createPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::createSong:
		if (createSongPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::createArtist:
		if (createArtistPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::createActor:
		if (createActorPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::edit:
		if (editPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;


	case PageName::save:
		if (savePage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case PageName::exitView:
		if (exitPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	default:
		break;
	}

	if (isCursorChange) {
		cursor.loadFromSystem(Cursor::Hand);
	}
	else {
		cursor.loadFromSystem(Cursor::Arrow);
	}
}

void GraphicView::mouseButtonPressedHandle(Event& event) {
	if (event.key.code == (int)Mouse::Left) {
		switch (pageName) {

		case PageName::home:
			pageName = homePage->mouseClick();
			break;

		case PageName::list:
			pageName = listPage->mouseClick();
			break;

		case PageName::details:
			pageName = detailsPage->mouseClick();
			break;

		case PageName::songActor:
			pageName = songActorPage->mouseClick();
			break;

		case PageName::create:
			pageName = createPage->mouseClick();
			break;

		case PageName::createSong:
			pageName = createSongPage->mouseClick();
			break;

		case PageName::createArtist:
			pageName = createArtistPage->mouseClick();
			break;

		case PageName::createActor:
			pageName = createActorPage->mouseClick();
			break;

		case PageName::edit:
			pageName = editPage->mouseClick();
			break;

		case PageName::save:
			pageName = savePage->mouseClick();
			break;

		case PageName::exitView:
			pageName = exitPage->mouseClick();
			break;

		default:
			break;
		};
	}
}

void GraphicView::mouseWheelMovedHandle(Event& event) {
	switch (pageName) {
	case PageName::list:
		listPage->scroll(event.mouseWheel.delta);
		break;

	case PageName::details:
		detailsPage->scroll(event.mouseWheel.delta);
		break;

	default:
		break;
	};
}

void GraphicView::drawPage() {
	switch (pageName) {
	case PageName::home:
		createTitle("Media library");
		homePage->draw();
		break;

	case PageName::list:
		createTitle("List");
		listPage->draw();
		break;

	case PageName::details:
		createTitle("Details: " + controller->selectedElement->getName());
		createFrame(width - 200, 340, 120);
		detailsPage->draw();
		break;

	case PageName::songActor:
		createTitle(controller->selectedActor != nullptr ? "Actor details" : "Song details");
		createFrame(width - 200, 340, 120);
		songActorPage->draw();
		break;

	case PageName::create:
		createTitle("Create element");
		createFrame(width - 200, 410);
		createPage->draw();
		break;

	case PageName::createSong:
		createTitle(controller->selectedSong != nullptr ? "Edit song" : "Create song");
		createFrame(width - 200, 410);
		createSongPage->draw();
		break;

	case PageName::createArtist:
		createTitle("Create artist");
		createFrame(width - 200, 410);
		createArtistPage->draw();
		break;

	case PageName::createActor:
		createTitle(controller->selectedActor != nullptr ? "Edit actor" : "Create actor");
		createFrame(width - 200, 410);
		createActorPage->draw();
		break;

	case PageName::edit:
		createTitle("Edit");
		createFrame(width - 200, 410);
		editPage->draw();
		break;

	case PageName::save:
		createTitle("Save file");
		createFrame(width - 200, 300, height / 2 - 150);
		savePage->draw();
		break;

	case PageName::exitView:
		createTitle("Exit");
		createFrame(width - 200, 300, height / 2 - 150);
		exitPage->draw();
		break;

	default:
		break;
	};
}

void GraphicView::createWindow() {
	loadFont();

	window = new RenderWindow(VideoMode(width, height), "Audio-Video Database", Style::Titlebar | Style::Close);

	window->display();
	View view(FloatRect(0, 0, float(width), float(height)));
	window->setView(view);
}

void GraphicView::createTitle(string title) {
	Text text(title, font, 48);
	text.setPosition(50, 16);

	RectangleShape line({ (float)width - 100, 2 });
	line.setFillColor({ 255, 255, 255, 100 });
	line.move(50, 80);

	window->draw(text);
	window->draw(line);
}

void GraphicView::createFrame(int width, int height, int offsetY) {
	RectangleShape frame;

	frame.setSize({ (float)width, (float)height });
	frame.setPosition((float)(this->width - width) / 2, (float)offsetY);
	frame.setFillColor({ 255, 255, 255, 160 });

	window->draw(frame);
}

void GraphicView::createBackground() {
	Sprite background;
	Texture texture;

	if (!texture.loadFromFile(resourcePath + "bgr.jpg")) {
		cout << "Fail load bgr";
	}

	background.setTexture(texture);
	background.setScale(0.5, 0.5);

	window->draw(background);
}

void GraphicView::cleanPage() {
	delete homePage;
	delete listPage;
	delete detailsPage;
	delete songActorPage;
	delete createPage;
	delete editPage;
	delete createSongPage;
	delete createArtistPage;
	delete createActorPage;
	delete savePage;
	delete exitPage;
	controller->clean();
}

void GraphicView::loadFont() {
	if (!font.loadFromFile(resourcePath + "font.ttf")) {
		cout << "Fail load font";
	}
}

