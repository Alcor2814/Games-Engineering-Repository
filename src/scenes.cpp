#include "scenes.hpp"

std::shared_ptr<Scene> Scenes::maze;

void MazeScene::load() {
    std::shared_ptr<Entity> player = std::make_shared<Player>();
    _entities.push_back(player);
    reset();

}
void MazeScene::reset() {
    _entities[0]->set_position(...);
}