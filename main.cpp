
#include <SFML/Graphics.hpp>
#include "classes/Config.h"
#include "classes/Game.h"

int main()
{
    Config config("../config.ini");
    Game game(config);
    while (game.window->isOpen())
    {
        sf::Event event;
        while (game.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.window->close();
        }
        game.update();
        game.window->clear();
        game.draw();
        game.window->display();
    }
    return 0;
}
