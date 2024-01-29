#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Vector.h"

using namespace sf;

struct Entity{
    int angle=0;
    V2 position;
    float speed;
    CircleShape* shape;

    void draw(sf::RenderWindow* window){
        window->draw(*shape);
    }

    void rotate(int a){
        angle += a;
        angle %= 360;
        shape->setRotation(angle);
    }

    void move(V2&& v){
        position.x += v.x*speed;
        position.y += v.y*speed;
        shape->setPosition(position.x,position.y);
    }
};