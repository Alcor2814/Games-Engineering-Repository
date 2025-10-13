//player.cpp
#include "player.hpp"
#include "game_parameters.hpp"
using namespace sf;
using namespace std;

void Player::update(double dt) {
	//Move left
	if (sf::Keyboard::isKeyPressed(Parameters::controls[0]) && getPosition().x < Parameters::gameWidth) {
		move(dt * (false ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(Parameters::controls[1]) && getPosition().x > 0) {
		move(dt * (true ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}
	//Move Up
	if (sf::Keyboard::isKeyPressed(Parameters::controls[2]) && getPosition().y < Parameters::gameHeight) {
		move(dt * (false ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}
	//Move Down
	if (sf::Keyboard::isKeyPressed(param::controls[3]) && getPosition().y > 0) {
		move(dt * (true ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}

	Entity::update(dt);
}

Player::Player() : Entity(make_unique<CircleShape>(_radius_)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(sf::Vector2f(_radius, _radius_));
}

void Player::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}