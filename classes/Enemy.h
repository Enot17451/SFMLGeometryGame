#pragma once

#include "Entity.h"

struct Enemy: Entity{

    Enemy(){

    }

};

struct EnemyFactory{

    explicit EnemyFactory(Config config){

    }

    Enemy* create(){

    }
};