//game_system.hpp
#pragma once

struct GameSystem {
	//Parameters
	struct Parameters {
		static constexpr int gameWidth = 800;
		static constexpr int gameHeight = 600;
		static constexpr int sprite_size = 32;
	};

	// Game Sys
	static void init();
	static void clean();
	static void update(const float& dt);
	static void render(sf::RenderWindow& window);
	static void reset();
};