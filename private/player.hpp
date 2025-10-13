//player.hpp
#pragma once
#include "entity.h"

class Player : public Entity {
	public:
		void update(const float& dt) override;
		Player();
		void render(sf::RenderWindow& window) const override;
	private:
		static constexpr float _radius = 25.f;
		static constexpr _speed = 200.0f;
};