#include <iostream>
#include "game_system.hpp"
#include "game_parameters.hpp"

void Scene::update(const float &dt) {
    for (std::shared_ptr<Entity>& ent: _entities) {
        ent->update(dt);
    }
}
void Scene::render(sf::RenderWindow& window) {
    for (std::shared_ptr<Entity> &ent: _entities)
    {
        ent->render(window);
    }
}

void GameSystem::start(unsigned int width, unsigned int height, const std::string& name) {
    sf::RenderWindow window(sf::VideoMode({ width, height }), name);
    GameSystem::_init();
    sf::Event event;
    while (window.isOpen()) {
        static sf::Clock clock;
        float dt = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                clean();
                return;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        GameSystem::_update(dt);
        GameSystem::_render(window);
        sf::sleep(sf::seconds(Parameters::time_step));
        //Wait for Vsync
        window.display();
    }
    window.close();
    GameSystem::clean();
}

/// <summary>
/// Initialises any values that need to be loaded.
/// </summary>
void GameSystem::_init() {

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
void GameSystem::_update(const float& dt) {

}

/// <summary>
/// Renders entities.
/// </summary>
/// <param name="window">The display window.</param>
void GameSystem::_render(sf::RenderWindow& window) {

}

/// <summary>
/// Cleans up anything that may not have been cleaned by the end of the game.
/// </summary>
void GameSystem::clean() {

}

void GameSystem::set_active_scene(const std::shared_ptr<Scene>& act_sc)
{

}