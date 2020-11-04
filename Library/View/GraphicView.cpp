#include "GraphicView.h"

GraphicView::GraphicView(Controller*& ctr) {
	this->controller = ctr;

	createWindow();
	page = home;
	homePage = new HomePage(controller, window, font);
	listPage = new ListPage(controller, window, font);
	createPage = new CreatePage(controller, window, font);
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

	default:
		break;
	};
	// cout << "Scroll: " << event.mouseWheel.delta << endl;
}

void GraphicView::drawPage() {
	switch (page) {
	case home:
		createTitle("Media library");
		homePage->draw();
		break;

	case collection:
		createTitle("List");
		listPage->draw();
		break;

	case create:
		createTitle("Create element");
		createFrame(width - 200, 410);
		createPage->draw();
		break;

	case createSong:
		createTitle("Create song");
		createFrame(width - 200, 410);
		createSongPage->draw();
		break;

	case createArtist:
		createTitle("Create artist");
		createFrame(width - 200, 410);
		createArtistPage->draw();
		break;	
	
	case createActor:
		createTitle("Create actor");
		createFrame(width - 200, 410);
		createActorPage->draw();
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

void GraphicView::createFrame(float width, float height, float offsetY) {
	RectangleShape frame;
	frame.setSize(Vector2f(width, height));
	frame.move((this->width - width) / 2, offsetY);
	frame.setFillColor({ 255, 255, 255, 120 });

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