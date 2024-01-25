cmake_minimum_required(VERSION 3.27)

project(game1)

set(CMAKE_CXX_STANDARD 20)

set(SFML_ROOT "D:/dev/SFMLGW64/")

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(game1 main.cpp
        classes/Vector.h
        classes/RandomRange.h
        classes/Config.h
        classes/Game.h
        classes/Player.h
        classes/Enemy.h
        classes/Bullet.h
        classes/Entity.h
)

target_link_libraries(game1 sfml-system sfml-window sfml-graphics)
