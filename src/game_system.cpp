#include <iostream>
#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"
#include "bullet.hpp"

/// <summary>
/// Initialises any values that need to be loaded.
/// </summary>
void GameSystem::init() {
	if (!GameSystem::spritesheet.loadFromFile("resources/images/invaders_sheet.png")) {
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}

	std::shared_ptr<Invader> inv;
	for (size_t i = 0; i < 6; i++)
	{
		inv = std::make_shared<Invader>(
			GameSystem::spritesheet,
			sf::IntRect(sf::Vector2i((i * 32), 0), sf::Vector2i(Parameters::sprite_size, Parameters::sprite_size)),
			sf::Vector2f({ (100.0f + (i * 32)), 100.0f }));
		GameSystem::ships.push_back(inv);
	}

	GameSystem::ships.push_back(std::make_shared<Player>());
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
	for (std::shared_ptr<Ship> &s : ships)
	{
		s->Update(dt);
	}
	Bullet::update(dt);
}

/// <summary>
/// Renders entities.
/// </summary>
/// <param name="window">The display window.</param>
void GameSystem::render(sf::RenderWindow& window) {
	for (const std::shared_ptr<Ship>& s : ships)
	{
		window.draw(*(s.get()));
	}
	Bullet::render(window);
}

/// <summary>
/// Cleans up anything that may not have been cleaned by the end of the game.
/// </summary>
void GameSystem::clean() {
	//free up the memory if necessary.
	for (std::shared_ptr<Ship>& ship : ships)
		ship.reset();//free up the memory of this shared pointer
	ships.clear();//clear the vector to be sure we free up any memory left.
}
