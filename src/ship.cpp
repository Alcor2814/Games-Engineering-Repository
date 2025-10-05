//ship.cpp
#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"

//usings
using param = Parameters;
using gs = GameSystem;

//Initialise static variable
std::vector<std::shared_ptr<Ship>> gs::ships{};

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
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f);
	if ((direction && getPosition().x > param::gameWidth - param::sprite_size/2.f) ||
		(!direction && getPosition().x < param::sprite_size/2.f))
	{
		direction = !direction;
		speed += Invader::acceleration;
		Move_Down();
	}
}

void Invader::Move_Down() {
	for (const std::shared_ptr<Ship>& s : gs::ships)
	{
		s->setPosition(s->getPosition().x, s->getPosition().y + param::sprite_size);
	}
}

bool Invader::direction;
float Invader::speed;
float Invader::acceleration = 0.0f;