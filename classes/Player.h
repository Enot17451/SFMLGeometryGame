#pragma once

#include "Vector.h"
#include "Entity.h"

using namespace std;

struct Player:Entity{

    Player(Config config){
        speed = config.playerSpeed;
        position = new Vector(config.screenWidth/2,config.screenHeight/2);
        shape = new CircleShape(config.playerRadius,config.playerVertices);
        shape->setFillColor(sf::Color(config.playerR,config.playerG,config.playerB));
        shape->setPosition(position->x,position->y);
    }

    void draw(RenderWindow* window){
        window->draw(*shape);
    }

    void update(){

    }
};