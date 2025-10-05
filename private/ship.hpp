//ship.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
public:
	//Constructor
		Ship();
	//Copy Constructor
		Ship(const Ship& s);
	//Constructor that takes a Sprite.
		Ship(const sf::Texture& spritesheet, sf::IntRect ir);
	//Virtual deconstructor
		virtual ~Ship() = 0;
	//Updater
		virtual void Update(const float& dt);
protected:
	sf::IntRect _sprite;
};

class Invader : public Ship {
	public:
		Invader();
		Invader(const Invader& inv);
		Invader(const sf::Texture& spritesheet, sf::IntRect ir, sf::Vector2f pos);
		void Update(const float& dt) override;
};