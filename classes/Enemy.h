#pragma once

#include "Entity.h"
#include "RandomRange.h"

struct Enemy: Entity{

    Enemy(){}

    void update(){

    }

};

struct EnemyFactory{

    Config* config;
    RandomEngine random;

    explicit EnemyFactory(Config* c){
        config = c;
    }

    Enemy* create(){
        Enemy* e = new Enemy();
        e->speed = getSpeed();
        e->shape = new CircleShape(config->playerRadius,getVertices());
        e->shape->setFillColor(Color(config->playerR,config->playerG,config->playerB));
        int x = random.get(0+config->enemyRadius,config->screenWidth-config->playerRadius);
        int y = random.get(0+config->enemyRadius,config->screenHeight-config->playerRadius);
        e->shape->setPosition(x,y);
        e->shape->setOrigin(config->enemyRadius,config->enemyRadius);
        return e;
    }

    int getSpeed(){
        return random.get(config->enemyMinSpeed,config->enemyMaxSpeed);
    }

    int getVertices(){
        return random.get(config->enemyMinVertices,config->enemyMaxVertices);
    }
};