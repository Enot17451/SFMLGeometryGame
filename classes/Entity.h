#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Vector.h"

using namespace sf;

struct Entity{
    V2* position;
    int speed;
    CircleShape* shape;

    void draw(sf::RenderWindow* window){
        window->draw(*shape);
    }
};