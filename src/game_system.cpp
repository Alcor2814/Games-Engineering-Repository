#include <iostream>
#include "ship.hpp"
#include "game_system.hpp"

/// <summary>
/// Initialises any values that need to be loaded.
/// </summary>
void GameSystem::init() {
	if (!GameSystem::spritesheet.loadFromFile("resources/images/invaders_sheet.png")) {
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
	else {
		std::cout << "Loaded spritesheet" << std::endl;
	}
	std::shared_ptr<Invader> inv = std::make_shared<Invader>(
		GameSystem::spritesheet,
		sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
		sf::Vector2f({ 100.0f, 100.0f }));
	GameSystem::ships.push_back(inv);
}

/// <summary>
/// For resetting in games where resets are possible.
/// </summary>
void GameSystem::reset() {

}

/// <summary>
/// Updates entities.
/// </summary>
/// <param name="dt"></param>
void GameSystem::update(const float& dt) {

}

/// <summary>
/// Renders entities.
/// </summary>
/// <param name="window">The display window.</param>
void GameSystem::render(sf::RenderWindow& window) {
	window.draw(GameSystem::invader);
}

/// <summary>
/// Cleans up anything that may not have been cleaned by the end of the game.
/// </summary>
void GameSystem::clean() {
	//free up the memory if necessary.
}
