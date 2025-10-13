//game_parameters.hpp
#pragma once

//Parameters
struct Parameters {
	static constexpr int gameWidth = 800;
	static constexpr int gameHeight = 600;
	static constexpr float time_step = 0.017f; //60 fps

	static constexpr sf::Keyboard::Key controls[4] = {
		sf::Keyboard::Left,   // Player Left
		sf::Keyboard::Right,   // Player Right
		sf::Keyboard::Up,   // Player Up
		sf::Keyboard::Down,   // Player Down
	};
};