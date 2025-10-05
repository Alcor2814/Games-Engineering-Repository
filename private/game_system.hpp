//game_system.hpp
#pragma once
#include <vector>
#include <memory>
#include "ship.hpp"

struct GameSystem {
	//Global variables
	std::vector<std::shared_ptr<Ship>> ships; //vector of shared pointers to ships
	sf::Texture spritesheet;
	sf::Sprite invader;

	//Parameters
	struct Parameters {
		static constexpr int gameWidth = 800;
		static constexpr int gameHeight = 600;
		static constexpr int sprite_size = 32;
	};

	// Game System functions
	 void init();
	 void clean();
	 void update(const float& dt);
	 void render(sf::RenderWindow& window);
	 void reset();
};