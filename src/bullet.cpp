//bullet.cpp
#include "bullet.hpp"
#include "game_parameters.hpp"
#include "game_system.hpp"

using namespace sf;
using namespace std;

unsigned char Bullet::_bulletPointer;
Bullet Bullet::_bullets[256];

Bullet::Bullet() {};

void Bullet::update(const float& dt) {
    for (Bullet& b : _bullets)
    {
        b._update(dt);
    }
}

void Bullet::render(sf::RenderWindow& window) {
    for (Bullet& b : _bullets)
    {
        window.draw(b);
    }
}

void Bullet::fire(const sf::Vector2f& pos, const bool mode) {
	Bullet& bullet = _bullets[++_bulletPointer];
	if (mode)
		bullet.setTextureRect(sf::IntRect(sf::Vector2i(64, 32), sf::Vector2i(Parameters::sprite_size, Parameters::sprite_size)));
	else
		bullet.setTextureRect(sf::IntRect(sf::Vector2i(96, 32), sf::Vector2i(Parameters::sprite_size, Parameters::sprite_size)));
	bullet.setPosition(pos);
	bullet._mode = mode;
}

void Bullet::init() {
	for (int i = 0; i < 256; i++)
	{
		_bullets[i].setTexture(GameSystem::spritesheet);
		_bullets[i].setOrigin(Parameters::sprite_size / 2.f, Parameters::sprite_size / 2.f);
		_bullets[i].setPosition(-100, -100);
	}
}

void Bullet::_update(const float& dt) {
    if (getPosition().y < -Parameters::sprite_size || getPosition().y > Parameters::gameHeight + Parameters::sprite_size) {
        //off screen - do nothing
        return;
    }
    else {
        move(sf::Vector2f(0, dt * Parameters::bulletSpeed * (_mode ? -1.0f : 1.0f)));
        const sf::FloatRect boundingBox = getGlobalBounds();
        std::shared_ptr<Ship>& player = GameSystem::ships[0]; //we know that the first ship is the player
        for (std::shared_ptr<Ship>& s : GameSystem::ships) {
            if ((_mode && s == player) || (!_mode && s != player)) {
                //player bullets don't collide with player
                continue;
            }
            if (!s->exploded() &&
                s->getGlobalBounds().intersects(boundingBox)) {
                //Explode the ship
                s->explode();
                //warp bullet off-screen
                setPosition(sf::Vector2f(-100, -100));
                return;
            }
        }
    }
}

