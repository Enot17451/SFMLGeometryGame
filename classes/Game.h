#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace sf;
using namespace std;

struct Game {
    vector<Enemy*> enemies;
    vector<Bullet*> bullets;
    Player* player;
    EnemyFactory* ef;
    BulletFactory* bf;
    RenderWindow* window;
    Text text;
    bool paused = false;
    int score = 0;

    Game(Config* c){
        window = new RenderWindow();
        if(c->fullScreen){
            window->create(VideoMode(c->screenWidth, c->screenHeight), "Game",Style::Fullscreen);
        } else{
            window->create(VideoMode(c->screenWidth, c->screenHeight), "Game",Style::Default);
        }
        player = new Player(c);
        ef = new EnemyFactory(c);
        bf = new BulletFactory(c);
    };

    void update(){
        player->update();
        for (Enemy* e:enemies) {
            e->update();
        }
        for (Bullet* b:bullets) {
            b->update();
        }
    }

    void draw(){
        player->draw(window);
        for (Enemy* e:enemies) {
            e->draw(window);
        }
        for (Bullet* b:bullets) {
            b->draw(window);
        }
    }
};
