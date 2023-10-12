#include "../includes/Animation.hpp"

#define TILE_SIZE 64


Animation::Animation(sf::Vector2u imageCount, float switchTime) 
: 	_imageCount(imageCount), _switchTime(switchTime)
{

	_timeSinceLastImage  = 0.0f;
	_currentImage.x = 0;
	textureRect.width = TILE_SIZE;
	textureRect.height = TILE_SIZE;

	return ;
}

Animation::~Animation() {
	return ;
}

void	Animation::update(int row, float deltaTime, bool facingLeft) {

	if (row >= 0) {
		_currentImage.y = row;
		_timeSinceLastImage += deltaTime;

		if (_timeSinceLastImage >= _switchTime)
		{
			_timeSinceLastImage -= _switchTime;
			_currentImage.x++;

			if (_currentImage.x > _imageCount.x)
				_currentImage.x = 0;
		}

		textureRect.top  = _currentImage.y * textureRect.height;

		if (facingLeft) {
			textureRect.left = (_currentImage.x + 1) * abs(textureRect.width);
			textureRect.width = -abs(textureRect.width);
		}
		else {
			textureRect.left = _currentImage.x * textureRect.width;
			textureRect.width = abs(textureRect.width);
		}
	}
}