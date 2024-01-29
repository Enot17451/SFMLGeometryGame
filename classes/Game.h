#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "MyText.h"

using namespace sf;
using namespace std;

struct Game {
    vector<Enemy*> enemies;
    vector<Bullet*> bullets;
    Clock clock;
    Player* player;
    EnemyFactory* ef;
    BulletFactory* bf;
    RenderWindow* window;
    MyText* text = new MyText("Hello");
    bool paused = false;
    int score = 0;

    Game(Config* c){
        window = new RenderWindow();
        window->setVerticalSyncEnabled(true);

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
        clock.restart();
        player->update();
        for (Enemy* e:enemies) {
            e->update();
        }
        for (Bullet* b:bullets) {
            b->update();
        }
        unsigned long a = clock.getElapsedTime().asMicroseconds();
        cout << a << "\n";
        sleep(microseconds(16666-a));
    }

    void draw(){
        text->draw(window);
        player->draw(window);
        for (Enemy* e:enemies) {
            e->draw(window);
        }
        for (Bullet* b:bullets) {
            b->draw(window);
        }
    }
};
