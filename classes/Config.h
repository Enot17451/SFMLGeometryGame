#pragma once

#include <SFML/Graphics.hpp>
#include  <string>
#include  <fstream>

using namespace std;

struct Config {
    string temp;
    int screenWidth;
    int screenHeight;
    int fps;
    bool fullScreen;

    string fontFileName;
    int fontSize;
    int fontRed;
    int fontGreen;
    int fontBlue;

    int playerRadius;
    int playerSpeed;
    int playerR;
    int playerG;
    int playerB;
    int playerVertices;

    int enemyRadius;
    int enemyMinSpeed;
    int enemyMaxSpeed;
    int enemyR;
    int enemyG;
    int enemyB;
    int enemyMinVertices;
    int enemyMaxVertices;
    int enemySmallLife;
    int enemySpawnTime;

    int bulletRadius;
    int bulletSpeed;
    int bulletR;
    int bulletG;
    int bulletB;
    int bulletVertices;
    int bulletLife;

    void loadGame(ifstream& file) {
        file >> temp;
        file >> temp >> screenWidth >> screenHeight >> fps >> fullScreen;
    }

    void loadFont(ifstream& file) {
        file >> temp;
        file >> temp >> fontFileName >> fontSize >> fontRed >> fontGreen >> fontBlue;
    }

    void loadPlayer(ifstream& file) {
        file >> temp;
        file >> temp >> playerRadius >> playerSpeed >> playerR >> playerG >> playerB >> playerVertices;
    }

    void loadEnemy(ifstream& file) {
        file >> temp;
        file >> temp >> enemyRadius >> enemyMinSpeed >> enemyMaxSpeed >> enemyR >> enemyG >> enemyB;
        file >> enemyMinVertices >> enemyMaxVertices >> enemySmallLife >> enemySpawnTime;
    }

    void loadBullet(ifstream& file) {
        file >> temp;
        file >> temp >> bulletRadius >> bulletSpeed >> bulletR >> bulletG >> bulletB >> bulletVertices >> bulletLife;
    }

    Config(string fileName) {
        ifstream file(fileName);
        loadGame(file);
        loadFont(file);
        loadPlayer(file);
        loadEnemy(file);
        loadBullet(file);
    }
};