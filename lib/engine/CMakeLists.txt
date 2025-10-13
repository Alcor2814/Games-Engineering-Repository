add_library(${PROJECT_NAME} STATIC engine/game_system.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE engine)
target_link_libraries(${PROJECT_NAME} sfml-graphics)