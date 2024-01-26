#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Vector.h"

using namespace sf;

struct Entity{
    float angle=0;
    V2* position;
    float speed;
    CircleShape* shape;

    void draw(sf::RenderWindow* window){
        window->draw(*shape);
    }
};