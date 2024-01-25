#pragma once

#include "Entity.h"

struct Bullet:Entity{

    void update(){

    }
};

struct BulletFactory{

    BulletFactory(Config c){

    }

    Bullet* create(){

    }

};