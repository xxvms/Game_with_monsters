cmake_minimum_required(VERSION 3.8)
project(Game_with_monsters)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
SET(CMAKE_C_FLAGS_DEBUG "-O0")

set(SOURCE_FILES main.cpp Move_direction.h Game_map.cpp Game_map.h rang.hpp Player.cpp Player.h)
add_executable(Game_with_monsters ${SOURCE_FILES})