#include <SFML/Graphics.hpp>
#include "game_system.hpp"

//Parameters
const int gameWidth = 800;
const int gameHeight = 600;
const float time_step = 0.017f; //60 fps

GameSystem gameSystem;

int main() {
	//create the window
	sf::RenderWindow window(sf::VideoMode({ gameWidth, gameHeight }), "NAME");
	window.setVerticalSyncEnabled(true);

	//initialise and load
	gameSystem.init();
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
		gameSystem.update(dt);
		gameSystem.render(window);
		//wait for the time_step to finish before displaying the next frame.
		sf::sleep(sf::seconds(time_step));
		window.display();
	}
	//Unload and shutdown
	gameSystem.clean();
}
