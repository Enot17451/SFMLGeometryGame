
#include <SFML/Graphics.hpp>
#include "classes/Config.h"
#include "classes/Game.h"

using namespace std;


int main()
{
    Config* config = new Config("../config.ini");
    Game game(config);

    while (game.window->isOpen())
    {
        Event event;
        while (game.window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                game.window->close();
        }
        game.update();
        game.window->clear();
        game.draw();
        game.window->display();
    }
    return 0;
}
