//player.cpp
#include "player.hpp"
#include "game_parameters.hpp"
using namespace sf;
using namespace std;

void Player::update(const float& dt) {
	//Move left
	if (sf::Keyboard::isKeyPressed(Parameters::controls[0]) && get_position().x < Parameters::gameWidth) {
		move(sf::Vector2f(dt * (false ? 1.0f : -1.0f) * Player::_speed, 0.0f));
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(Parameters::controls[1]) && get_position().x > 0) {
		move(sf::Vector2f(dt * (true ? 1.0f : -1.0f) * Player::_speed, 0.0f));
	}
	//Move Up
	if (sf::Keyboard::isKeyPressed(Parameters::controls[2]) && get_position().y < Parameters::gameHeight) {
		move(sf::Vector2f(dt * (false ? 1.0f : -1.0f) * Player::_speed, 0.0f));
	}
	//Move Down
	if (sf::Keyboard::isKeyPressed(Parameters::controls[3]) && get_position().y > 0) {
		move(sf::Vector2f(dt * (true ? 1.0f : -1.0f) * Player::_speed, 0.0f));
	}

	Entity::update(dt);
}

Player::Player() : Entity(make_unique<CircleShape>(_radius)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}