cmake_minimum_required(VERSION 3.21)
project(tetris C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

add_executable(tetris src/main.c src/game.c include/game.h src/console.c src/input.c include/input.h)
