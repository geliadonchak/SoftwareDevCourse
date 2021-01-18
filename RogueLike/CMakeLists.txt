cmake_minimum_required(VERSION 3.16)
project(roguelike)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -lncurses")

add_executable(roguelike main.cpp
        characters.cpp
        map.cpp
        graphics.cpp
        game.cpp
        utils/config.cpp utils/config.h
        visitors/wall_visitor.cpp
        visitors/win_condition_visitor.cpp
        visitors/attack_visitor.cpp
        scene.cpp scene.h utils/utils.cpp)

target_link_libraries(roguelike ${CURSES_LIBRARIES})
