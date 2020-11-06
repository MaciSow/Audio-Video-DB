#include "GraphicView.h"

GraphicView::GraphicView(MainController*& ctr) {
	this->controller = ctr;

	createWindow();
	page = home;
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
	}
}

void GraphicView::textEnteredHandle(Event& event) {
	switch (page) {
	case home:
		break;

	case create:
		createPage->textEntered(event);
		break;

	case createSong:
		createSongPage->textEntered(event);
		break;

	case createArtist:
		createArtistPage->textEntered(event);
		break;

	case createActor:
		createActorPage->textEntered(event);
		break;

	case edit:
		editPage->textEntered(event);
		break;

	case save:
		savePage->textEntered(event);
		break;

	default:
		break;
	}
}

void GraphicView::mouseMovedHandle() {
	bool isCursorChange = false;

	switch (page) {
	case home:
		if (homePage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case collection:
		if (listPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case details:
		if (detailsPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case songActor:
		if (songActorPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case create:
		if (createPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case createSong:
		if (createSongPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case createArtist:
		if (createArtistPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case createActor:
		if (createActorPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case edit:
		if (editPage->isMouseOver()) {
			isCursorChange = true;
		}
		break;


	case save:
		if (savePage->isMouseOver()) {
			isCursorChange = true;
		}
		break;

	case exitView:
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
		switch (page) {
		case home:
			page = homePage->mouseClick();
			break;

		case collection:
			page = listPage->mouseClick();
			break;

		case details:
			page = detailsPage->mouseClick();
			break;

		case songActor:
			page = songActorPage->mouseClick();
			break;

		case create:
			page = createPage->mouseClick();
			break;

		case createSong:
			page = createSongPage->mouseClick();
			break;

		case createArtist:
			page = createArtistPage->mouseClick();
			break;

		case createActor:
			page = createActorPage->mouseClick();
			break;

		case edit:
			page = editPage->mouseClick();
			break;

		case save:
			page = savePage->mouseClick();
			break;

		case exitView:
			page = exitPage->mouseClick();
			break;

		default:
			break;
		};
	}
}

void GraphicView::mouseWheelMovedHandle(Event& event) {
	switch (page) {
	case collection:
		listPage->scroll(event.mouseWheel.delta);
		break;

	case details:
		detailsPage->scroll(event.mouseWheel.delta);
		break;

	default:
		break;
	};
	// cout << "Scroll: " << event.mouseWheel.delta << endl;
}

void GraphicView::drawPage() {

	//if (controller->selectedActor != nullptr)
	//{
	//	cout << "selected" << endl;
	//}
	//else {
	//	cout << "unselected" << endl;
	//}

	switch (page) {
	case home:
		createTitle("Media library");
		homePage->draw();
		break;

	case collection:
		createTitle("List");
		listPage->draw();
		break;

	case details:
		createTitle("Details: " + controller->selectedElement->getName());
		createFrame(width - 200, 340, 120);
		detailsPage->draw();
		break;

	case songActor:
		createTitle(controller->selectedActor != nullptr ? "Actor details" : "Song details");
		createFrame(width - 200, 340, 120);
		songActorPage->draw();
		break;

	case create:
		createTitle("Create element");
		createFrame(width - 200, 410);
		createPage->draw();
		break;

	case createSong:
		createTitle(controller->selectedSong != nullptr ? "Edit song" : "Create song");
		createFrame(width - 200, 410);
		createSongPage->draw();
		break;

	case createArtist:
		createTitle("Create artist");
		createFrame(width - 200, 410);
		createArtistPage->draw();
		break;

	case createActor:
		createTitle(controller->selectedActor != nullptr ? "Edit actor" : "Create actor");
		createFrame(width - 200, 410);
		createActorPage->draw();
		break;

	case edit:
		createTitle("Edit");
		createFrame(width - 200, 410);
		editPage->draw();
		break;

	case save:
		createTitle("Save file");
		createFrame(width - 200, 300, height / 2 - 150);
		savePage->draw();
		break;

	case exitView:
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

void GraphicView::loadFont() {
	if (!font.loadFromFile(resourcePath + "font.ttf")) {
		cout << "Fail load font";
	}
}