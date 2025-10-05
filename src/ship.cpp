//ship.cpp
#include "ship.hpp"

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

Invader::Invader() : Ship() {}
Invader::Invader(const Invader& inv) : Ship(inv) {}
Invader::Invader(const sf::Texture& spritesheet, sf::IntRect ir, sf::Vector2f pos) : Ship(spritesheet, ir) {
	setOrigin(sf::Vector2f(16.f, 16.f));
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);
}