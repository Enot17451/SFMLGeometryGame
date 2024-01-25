#pragma once
#include <ctime>
#include <random>
#include <cstdlib>

using namespace std;

struct RandomEngine{

    default_random_engine engine;

    RandomEngine(){
        random_device rd;
        engine.seed(rd());
    }

    int get(int from,int to){
        uniform_int_distribution<> distrib(from, to);
        return distrib(engine);
    }
};