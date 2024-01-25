#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Vector.h"

using namespace sf;

struct Entity{
    Vector* position;
    int speed;
    CircleShape* shape;

    void update(){

    }

    void draw(sf::RenderWindow* window){
        window->draw(*shape);
    }
};