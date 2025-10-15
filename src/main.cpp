#include <SFML/Graphics.hpp>
#include "game_system.hpp"
#include "game_parameters.hpp"
#include "scenes.hpp"

//main.cpp
int main() {
	Scenes::maze = std::make_shared<MazeScene>();
	std::static_pointer_cast<MazeScene>(Scenes::maze)->set_file_path(Parameters::mazes + "maze.txt");
	Scenes::maze->load();
	GameSystem::set_active_scene(Scenes::maze);
	GameSystem::start(Parameters::gameWidth, Parameters::gameHeight, "tile_maze");
	return 0;
}