#pragma once

#include "Vector.h"
#include "Entity.h"

using namespace sf;
using namespace std;

struct Player:Entity{

    Player(Config* config){
        speed = config->playerSpeed;
        shape = new CircleShape(config->playerRadius,config->playerVertices);
        shape->setFillColor(Color(config->playerR,config->playerG,config->playerB));
        int x = config->screenWidth/2-config->playerRadius;
        int y = config->screenHeight/2-config->playerRadius;
        shape->setPosition(x,y);
    }

    void update(){
        input();
    }

    void input(){
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            shape->move(-0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            shape->move(0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            shape->move(0.f, -0.1f);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            shape->move(0.f, 0.1f);
        }
    }
};