//game_system.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Scene {
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow& window);
	virtual void load() = 0;
	virtual void unload();
	std::vector<std::shared_ptr<Entity>>& get_entities() { return _entities; }

protected:
	std::vector<std::shared_ptr<Entity>> _entities;
};

class GameSystem {
public:
	static void start(unsigned int width, unsigned int height, const std::string& name);
	static void clean();
	static void reset();
	static void set_active_scene(const std::shared_ptr<Scene>& act_sc);
private:
	static void _init();
	static void _update(const float& dt);
	static void _render(sf::RenderWindow& window);
	static std::shared_ptr<Scene> _active_scene;
};