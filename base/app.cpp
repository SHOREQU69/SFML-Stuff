#include "app.h"

#include "../obj/player.h"
#include "../obj/grid.h"

sf::RenderWindow* app::window = nullptr;
grid g(20);
player p(100, 100, 20);

app::app(unsigned int size, std::string name) : size(size), name(name)
{
    window = new sf::RenderWindow(sf::VideoMode(size, size), name);
}

app::~app()
{
    delete window;
}

void app::events()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        g.modify_grid(event, get_mouse_pos());
    }
}

sf::Vector2i app::get_mouse_pos()
{
    return sf::Mouse::getPosition(*window);    
}

void app::tick(sf::Time delta_time)
{
    p.tick(delta_time);
    g.tick(get_mouse_pos());
}

void app::render()
{
    window->clear();

    g.render(window);
    p.render(window);
    window->draw(g.selected_tile);
    
    window->display();
}

void app::run()
{
    sf::Clock clock;
    sf::Time time_since_update = sf::Time::Zero;

    //more efficient game loop
    while (window->isOpen())
    {
        events();
        time_since_update += clock.restart();

        while(time_since_update > sf::seconds(1.f / FPS))
        {
            time_since_update -= sf::seconds(1.f / FPS);
            events();
            tick(sf::seconds(1.f / FPS));
        }

        render();
    }
}