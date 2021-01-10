cmake_minimum_required(VERSION 3.16)
project(roguelike)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

add_executable(roguelike main.cpp
        characters.cpp
        characters.h
        utils/config.cpp
        utils/config.h
        utils/types.h
        utils/utils.h
        external/json.h
        )