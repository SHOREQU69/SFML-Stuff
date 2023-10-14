#include <iostream>
#include <SFML/Graphics.hpp>

#include "obj/player.h"

int main()
{
    sf::Time t;
    Player* player = new Player(100, 100, 20);
    player->init(sf::Color::Yellow);
   
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tilemap");

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        player->tick(t);

        // draw the map
        window.clear();
        player->render(&window);
        window.display();
    }

    delete player;

    return 0;
}