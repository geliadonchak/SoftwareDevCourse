cmake_minimum_required(VERSION 3.16)
project(roguelike)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

add_executable(roguelike main.cpp
        characters.cpp
        map.cpp
        graphics.cpp
        game.cpp
        utils/config.cpp
        scenes/base_scene.cpp
        visitors/wall_visitor.cpp
        visitors/win_condition_visitor.cpp
        scenes/scene_controller.cpp
        )