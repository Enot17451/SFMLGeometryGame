#pragma once

#include <cmath>

struct Vector {
    float x;
    float y;

    Vector():x(0),y(0){}
    Vector(int x,int y):x(x),y(y){}

    bool operator == (Vector& v){
        return x == v.x and y == v.y;
    }

    bool operator != (Vector& v){
        return x != v.x or y != v.y;
    }

    void operator * (float a){
        x*=a;
        y*=a;
    }

    void operator / (float a){
        x/=a;
        y/=a;
    }

    float dist(Vector& v){
        return sqrt((x-v.x)*(x-v.x)+(y-v.y)*(y-v.y));
    }

    void operator += (Vector right)
    {
        x += right.x;
        y += right.y;
    }
};
