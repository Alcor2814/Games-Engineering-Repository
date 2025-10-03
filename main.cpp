#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_system.hpp"

//Objects of the game
sf::Texture spritesheet;
sf::Sprite invader;

int main() {
	const float time_step = 0.017f; //60 fps

	//create the window
	sf::RenderWindow window(sf::VideoMode({ GameSystem::Parameters::gameWidth, GameSystem::Parameters::gameHeight }), "Space Invaders");
	window.setVerticalSyncEnabled(true);

	//initialise and load
	GameSystem::init();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the win
			if (event.type == sf::Event::Closed)
				window.close();
		}

		static sf::Clock clock;
		const float dt = clock.restart().asSeconds();

		window.clear();
		GameSystem::update(dt);
		GameSystem::render(window);
		//wait for the time_step to finish before displaying the next frame.
		sf::sleep(sf::seconds(time_step));
		window.display();
	}
	//Unload and shutdown
	GameSystem::clean();
}

/// <summary>
/// Initialises any values that need to be loaded.
/// </summary>
void init() {
	if (!spritesheet.loadFromFile("resources/images/invaders_sheet.png")) {
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
	else {
		std::cout << "Loaded spritesheet" << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
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
	window.draw(invader);
}

/// <summary>
/// Cleans up anything that may not have been cleaned by the end of the game.
/// </summary>
void GameSystem::clean() {
	//free up the memory if necessary.
}
