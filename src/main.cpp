#include <SFML/Graphics.hpp>
#include "game_system.hpp"
#include "game_parameters.hpp"
#include "scenes.hpp"

//main.cpp
int main() {
	Scenes::maze = std::make_shared<MazeScene>();
	std::static_pointer_cast<MazeScene>(Scenes::maze)->set_file_path(param::maze_1);
	Scenes::maze->load();
	GameSystem::set_active_scene(Scenes::maze);
	GameSystem::start(Parameters::game_width, Parameters::game_height, "tile_maze");
	return 0;
}