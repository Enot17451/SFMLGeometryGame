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
        int x = config->screenWidth/2-config->playerRadius;
        int y = config->screenHeight/2-config->playerRadius;
        shape->setPosition(x,y);
        shape->setOrigin(config->playerRadius,config->playerRadius);
    }

    void update(){
        shape->rotate(0.03f);
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
            shape->move(speed*-0.0085f,speed*-0.0085f);
        } else if(up and right){
            shape->move(speed*0.0085f,speed*-0.0085f);
        } else if(down and left){
            shape->move(speed*-0.0085f,speed*0.0085f);
        } else if(down and right){
            shape->move(speed*0.0085f,speed*0.0085f);
        } else if(up)shape->move(0,-0.01f*speed);
        else if(down)shape->move(0,0.01f*speed);
        else if(left)shape->move(-0.01f*speed,0);
        else if(right)shape->move(0.01f*speed,0);
    }
};