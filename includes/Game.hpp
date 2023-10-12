#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>
# include <SFML/Window/VideoMode.hpp>
# include <SFML/Window/Keyboard.hpp>
# include <SFML/Window/Event.hpp>
# include <SFML/Window/Cursor.hpp>
# include <SFML/System/Vector2.hpp>

# include "Player.hpp"

class Game {

public:

	Game(void);
	~Game(void);

	void	run(void);

private:

	sf::RenderWindow	_gameWindow;
	sf::Cursor			_gameCursor;
	sf::Image			_gameCursorImage;

	Player 				_player;

	sf::Texture			background;
	sf::Sprite			bgSprite;

	float	deltaTime;

	void	processEvents(void);
	void	update(void);
	void	render(void);
};


#endif