#pragma once

#include "Entity.h"

struct Bullet:Entity{

    Bullet(){}

    void update(){}

};

struct BulletFactory{

    Config* config;

    explicit BulletFactory(Config* c){
        config = c;
    }

    Bullet* create(Player* player){
        Bullet* b = new Bullet();
        b->speed = config->bulletSpeed;
        b->shape = new CircleShape(config->bulletRadius,config->bulletVertices);
        b->shape->setFillColor(Color(config->bulletR,config->bulletG,config->bulletB));
        b->shape->setPosition(player->shape->getPosition().x,player->shape->getPosition().y);
        return b;
    }

};