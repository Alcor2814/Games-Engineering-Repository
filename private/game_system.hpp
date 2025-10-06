//game_system.hpp
#pragma once
#include <vector>
#include <memory>
#include "ship.hpp"

struct GameSystem {
	//Global variables
	static std::vector<std::shared_ptr<Ship>> ships; //vector of shared pointers to ships
	static sf::Texture spritesheet;
	sf::Sprite invader;

	static const sf::Keyboard::Key controls[3] = {
		sf::Keyboard::A,   // Player Left
		sf::Keyboard::Z,   // Player Right
		sf::Keyboard::Space,   // Player Fire
	};

	// Game System functions
	 void init();
	 void clean();
	 void update(const float& dt);
	 void render(sf::RenderWindow& window);
	 void reset();
};