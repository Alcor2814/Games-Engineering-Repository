//Parameters
struct Parameters {
	static constexpr int gameWidth = 800;
	static constexpr int gameHeight = 600;
	static constexpr int sprite_size = 32;
	static constexpr float time_step = 0.017f; //60 fps

	static constexpr sf::Keyboard::Key controls[3] = {
		sf::Keyboard::A,   // Player Left
		sf::Keyboard::Z,   // Player Right
		sf::Keyboard::Space,   // Player Fire
	};
};