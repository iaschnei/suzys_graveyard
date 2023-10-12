#include "../includes/Player.hpp"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 576

Player::Player(sf::Vector2u imageCount, float switchTime, float speed) 
: _animation(imageCount, switchTime), _speed(speed) {

	_row 		= 0;
	_facingLeft = false;

	if (_texture.loadFromFile("textures/suzy.png"))
		_body.setTexture(&_texture);

	_body.setSize(sf::Vector2f(64.0f, 64.0f));

    _body.setPosition(WINDOW_WIDTH / 2 - 32, WINDOW_HEIGHT / 2 - 32);
}

Player::~Player(void) {
	return ;
}

void Player::update(float deltaTime) {

	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= _speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += _speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= _speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += _speed * deltaTime;

	if (movement.x == 0.0f && movement.y == 0.0f) {
		_row = -1;
	}
	else if (movement.y == 0.0f) {
		_row = 2;
		if (movement.x <= 0.0f)
			_facingLeft = true;
		else
			_facingLeft = false;
	}
	else {
		if (movement.y < 0.0f)
			_row = 1;
		else
			_row = 0;
	}

	_animation.update(_row, deltaTime, _facingLeft);
	_body.setTextureRect(_animation.textureRect);
	_body.move(movement);

	return ;
}

void Player::draw(sf::RenderWindow &window) {

	window.draw(_body);
}
