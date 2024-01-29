#pragma once

#include "Vector.h"
#include "Entity.h"

using namespace sf;
using namespace std;

struct Player:Entity{

    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;

    Player(Config* config){
        speed = config->playerSpeed;
        shape = new CircleShape(config->playerRadius,config->playerVertices);
        shape->setFillColor(Color(config->playerR,config->playerG,config->playerB));
        position.x = config->screenWidth/2-config->playerRadius;
        position.y = config->screenHeight/2-config->playerRadius;
        shape->setPosition(position.x,position.y);
        shape->setOrigin(config->playerRadius,config->playerRadius);
    }

    void update(){
        rotate(2);
        input();
    }

    void input(){
        if (Keyboard::isKeyPressed(Keyboard::A)){
            left = true;
        }else{
            left = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            right = true;
        }else{
            right = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)){
            up = true;
        }else{
            up = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::S)){
            down = true;
        }else{
            down = false;
        }

        if(up and left){
            move(V2(-0.85,-0.85));
        } else if(up and right){
            move(V2(0.85,-0.85));
        } else if(down and left){
            move(V2(-0.85,0.85));
        } else if(down and right){
            move(V2(0.85,0.85));
        } else if(up){
            move(V2(0,-1));
        }else if(down){
            move(V2(0,1));
        }else if(left){
            move(V2(-1,0));
        }else if(right){
            move(V2(1,0));
        }
    }
};