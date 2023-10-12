#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <SFML/Graphics.hpp>
# include <SFML/Window/VideoMode.hpp>
# include <SFML/Window/Keyboard.hpp>
# include <SFML/System/Vector2.hpp>
# include "Animation.hpp"
# include <cmath>

class Player {

public:

	Player(sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void	update(float deltaTime);
	void	draw(sf::RenderWindow &window);
	
private:

	sf::RectangleShape 	_body;
	Animation			_animation;
	sf::Texture			_texture;


	int 				_row;
	float				_speed;
	bool				_facingLeft;
};

#endif
