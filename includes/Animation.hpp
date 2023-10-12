#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <SFML/Graphics.hpp>
# include <SFML/System/Vector2.hpp>


class Animation {

public:

	Animation(sf::Vector2u imageCount, float switchTime);
	~Animation();

	void	update(int row, float deltaTime, bool facingRight);
	
	sf::IntRect		textureRect;

private:

	sf::Vector2u	_imageCount;
	sf::Vector2u	_currentImage;

	float			_timeSinceLastImage;
	float 			_switchTime;

};


#endif