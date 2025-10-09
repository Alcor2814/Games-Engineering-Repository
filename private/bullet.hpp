//bullet.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
	public:
		// Updates all bullets by calling _Update on all bullets in the pool.
		static void update(const float& dt);
		// Renders all bullets.
		static void render(sf::RenderWindow& window);
		// Chooses an inactive bullet and uses it.
		static void fire(const sf::Vector2f& pos, const bool mode);
		// Sets up the bullets.
		static void init();
		~Bullet() = default;
	protected:
		Bullet();
		//false = player bullet, true = Enemy bullet
		static bool _mode = false;
		void _update(const float &dt);
		static unsigned char _bulletPointer;
		static Bullet _bullets[256];
};