//ship.cpp
#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"
#include <iostream>
#include <bullet.hpp>

//usings
using param = Parameters;
using gs = GameSystem;

//Initialise static variable
std::vector<std::shared_ptr<Ship>> gs::ships{};
sf::Texture gs::spritesheet;

Ship::Ship() {};
Ship::Ship(const Ship &s) :
	_sprite(s._sprite) {}
Ship::Ship(const sf::Texture& spritesheet, sf::IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};
void Ship::Update(const float& dt) {}
// Deconstructor
Ship::~Ship() = default;
void Ship::Move_Down() {};
void Ship::explode() {
	setTextureRect(sf::IntRect(sf::Vector2i(128, 32), sf::Vector2i(32, 32)));
	_exploded = true;
}

bool Ship::exploded() {
	return _exploded;
}

Invader::Invader() : Ship() {}
Invader::Invader(const Invader& inv) : Ship(inv) {}
Invader::Invader(const sf::Texture& spritesheet, sf::IntRect ir, sf::Vector2f pos) : Ship(spritesheet, ir) {
	setOrigin(sf::Vector2f(16.f, 16.f));
	setPosition(pos);
}
void Invader::Update(const float& dt) {
	Ship::Update(dt);
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f);
	if ((direction && getPosition().x > param::gameWidth - param::sprite_size/2.f) ||
		(!direction && getPosition().x < param::sprite_size/2.f))
	{
		direction = !direction;
		speed += Invader::acceleration;
		for (std::shared_ptr<Ship>& s : gs::ships)
		{
			s->Move_Down();
		}
	}
}

void Invader::Move_Down() {
	setPosition(getPosition().x, getPosition().y + param::sprite_size);
}

bool Invader::direction = false;
float Invader::speed = 20.0f;
float Invader::acceleration = 0.0f;

Player::Player() :
	Ship(gs::spritesheet, 
		sf::IntRect(sf::Vector2i((param::sprite_size * 5), param::sprite_size), sf::Vector2i(param::sprite_size, param::sprite_size)))
	{
		setOrigin(param::sprite_size / 2.f, param::sprite_size / 2.f);
		setPosition(param::gameWidth / 2.f, param::gameHeight - static_cast<float>(param::sprite_size));
	};

void Player::Update(const float& dt) {
	Ship::Update(dt);
	//Move left
	if (sf::Keyboard::isKeyPressed(param::controls[0]) && getPosition().x < param::gameWidth) {
		move(dt * (false ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(param::controls[1]) && getPosition().x > 0) {
		move(dt * (true ? 1.0f : -1.0f) * Player::speed, 0.0f);
	}

	//Fire Bullet
	static std::vector<std::shared_ptr<Bullet>> bullets;
	static float firetime = 0.0f;
	firetime -= dt;
	if (firetime <= 0 && sf::Keyboard::isKeyPressed(param::controls[2]))
	{
		Bullet::fire(getPosition(), false);
		firetime = 0.7f;
	}
}

void Player::Move_Down() { }

float Player::speed = 100.0f;