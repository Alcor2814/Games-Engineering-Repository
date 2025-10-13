//game_system.hpp
#pragma once
#include <SFML/Graphics.hpp>

struct GameSystem {
	//Global variables

	// Game System functions
	void init();
	void clean();
	void update(const float& dt);
	void render(sf::RenderWindow& window);
	void reset();
};