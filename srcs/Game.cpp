#include "../includes/Game.hpp"

// --------------------
// Constructor
// --------------------

#include <iostream>

Game::Game(void) : gameWindow(sf::VideoMode(640 , 640), "Game project", sf::Style::Titlebar | sf::Style::Close) {

	// -- Setup the window to open at the center of the screen ---
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
   	sf::Vector2i center(desktop.width/2 - gameWindow.getSize().x/2, desktop.height/2 - gameWindow.getSize().y/2);
    gameWindow.setPosition(center);
    gameWindow.setFramerateLimit(60);
	// -----------------------------------------------------------

    // -- Setup a custom cursor for the game (may look different based on operating system)
    if (gameCursorImage.loadFromFile("textures/cursor.png")) {
    	if (gameCursor.loadFromPixels(gameCursorImage.getPixelsPtr(), gameCursorImage.getSize(), sf::Vector2u(8,8)))
    		gameWindow.setMouseCursor(gameCursor);
    }
   	// -----------------------------------------------------------

	this->currentLevel = 1;

    return ;
}

// --------------------
// Member functions
// --------------------

void Game::run(void) {

	while (gameWindow.isOpen()) {
		processEvents();
		update();
		render();
	}

	return ;
}


void	Game::processEvents(void) {

	sf::Event event;

    while (gameWindow.pollEvent(event))
    {
    	switch (event.type)
   		{
	        case sf::Event::Closed:
	            gameWindow.close();
	            break;

	        case sf::Event::KeyPressed:
			    if (sf::Keyboard::Escape)
			    {
			    	gameWindow.close();
			    }
	            break;

	        default:
	        	break;
        }
    }

	return ;
}


void	Game::update(void) {
	return ;
}


void	Game::render(void) {

	gameWindow.clear();

    //------- Draw the game here: -------


    sf::Texture wall_texture;

    if (!wall_texture.loadFromFile("textures/map_1.png"))
    	return ;
    
    sf::Sprite wall_sprite;
	
	wall_sprite.setTexture(wall_texture);

	gameWindow.draw(wall_sprite);

    //-----------------------------------

    gameWindow.display();

	return ;
}