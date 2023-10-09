#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Window/VideoMode.hpp>
# include <SFML/Window/Keyboard.hpp>
# include <SFML/Window/Event.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System/Vector2.hpp>
# include <SFML/Window/Cursor.hpp>

class Game
{

public:

	Game(void);

	void	run(void);

	int currentLevel;

private:

	sf::RenderWindow	gameWindow;
	sf::Cursor			gameCursor;
	sf::Image			gameCursorImage;


	void	processEvents(void);
	void	update(void);
	void	render(void);
};


#endif