#pragma once

#include <cmath>

struct V2 {
    float x;
    float y;

    V2():x(0),y(0){}
    V2(int x,int y):x(x),y(y){}

    bool operator == (V2& v){
        return x == v.x and y == v.y;
    }

    bool operator != (V2& v){
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

    float dist(V2& v){
        return sqrt((x-v.x)*(x-v.x)+(y-v.y)*(y-v.y));
    }

    V2 normalize(){
        float invers = 1/len();
        float x1 = x*invers;
        float y1 = y*invers;
        return V2(x1,y1);
    }

    float len(){
        return sqrt(x*x+y*y);
    }

    void operator += (V2 right)
    {
        x += right.x;
        y += right.y;
    }
};
