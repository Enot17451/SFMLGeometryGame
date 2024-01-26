#pragma  once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct MyText{

    string message;
    Text* text = new Text();
    Font* font = new Font();

    MyText(string&& s){
        font->loadFromFile("../CascadiaMono.ttf");
        text->setFont(*font);
        text->setString(s);
        text->setCharacterSize(24);
        text->setPosition(10,10);
        text->setFillColor(Color::Red);
    }

    ~MyText(){
        delete font;
        delete text;
        text = nullptr;
        font = nullptr;
    }

    void setText(string&& s){
        text->setString(s);
    }

    void draw(RenderWindow* window){
        window->draw(*text);
    }

};

