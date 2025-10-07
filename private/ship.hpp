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
			virtual void Ship::Move_Down();
			bool is_exploded() const;
			virtual void explode();
	protected:
		sf::IntRect _sprite;
		bool _exploded = false;
};

class Invader : public Ship {
	public:
		Invader();
		Invader(const Invader& inv);
		Invader(const sf::Texture& spritesheet, sf::IntRect ir, sf::Vector2f pos);
		void Update(const float& dt) override;
		void Move_Down() override;

		static bool direction;
		static float speed, acceleration;
};

class Player : public Ship {
	public:
		Player();
		void Update(const float& dt) override;
		static float speed;
		void Move_Down() override;
};