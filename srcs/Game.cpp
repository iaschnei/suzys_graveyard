#include "../includes/Game.hpp"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 576

// --------------------
// Constructor & Destructor
// --------------------

Game::Game(void) : _gameWindow(sf::VideoMode(WINDOW_WIDTH , WINDOW_HEIGHT), "Suzy's Graveyard", sf::Style::Titlebar | sf::Style::Close),
_player(sf::Vector2u(3, 3), 0.2f, 128.0f) {

	deltaTime = 0.0f;

	// -- Setup the window to open at the center of the screen ---
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
   	sf::Vector2i center(desktop.width/2 - _gameWindow.getSize().x/2, desktop.height/2 - _gameWindow.getSize().y/2);
    _gameWindow.setPosition(center);
    _gameWindow.setFramerateLimit(60);
	// -----------------------------------------------------------

    // -- Setup a custom cursor for the game (may look different based on operating system)
    if (_gameCursorImage.loadFromFile("textures/cursor.png")) {
    	if (_gameCursor.loadFromPixels(_gameCursorImage.getPixelsPtr(), _gameCursorImage.getSize(), sf::Vector2u(8,8)))
    		_gameWindow.setMouseCursor(_gameCursor);
    }
   	// -----------------------------------------------------------

    return ;
}

Game::~Game(void) {
	return ;
}

// --------------------
// Member functions
// --------------------

void Game::run(void) {

	sf::Clock	clock;

	while (_gameWindow.isOpen()) {

		deltaTime = clock.restart().asSeconds();

		processEvents();
		update();
		render();
	}

	return ;
}


void	Game::processEvents(void) {

	sf::Event event;

    while (_gameWindow.pollEvent(event))
    {
    	switch (event.type)
   		{
	        case sf::Event::Closed:
	            _gameWindow.close();
	            break;

	        // case sf::Event::KeyPressed:
			//     if (sf::Keyboard::Escape)
			//     {
			//     	_gameWindow.close();
			//     }
	        //     break;
        }
    }

	return ;
}


void	Game::update(void) {

	_player.update(deltaTime);

	return ;
}


void	Game::render(void) {

	background.loadFromFile("textures/graveyard.png");
	bgSprite.setTexture(background);
	bgSprite.setPosition(0.0f, 0.0f);	

	_gameWindow.clear();

	_gameWindow.draw(bgSprite);
	_player.draw(_gameWindow);

    _gameWindow.display();

	return ;
}