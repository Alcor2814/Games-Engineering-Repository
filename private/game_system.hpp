//game_system.hpp
#pragma once
#include <SFML/Graphics.hpp>

struct GameSystem {
	//Global variables

	// Game System functions
	void init();
	void clean();
	void update(const float& dt);
	void render(sf::RenderWindow& window);
	void reset();
};

class Scene
{
public:
    Scene() = default;

    virtual ~Scene() = default;
    virtual void update(const float& dt);
    virtual void render(sf::RenderWindow& window);
    virtual void load() = 0;
    virtual void unload();

    std::vector<std::shared_ptr<Entity>>& get_entities() { return m_entities; }

protected:
    std::vector<std::shared_ptr<Entity>> m_entities;
};