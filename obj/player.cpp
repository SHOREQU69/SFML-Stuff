#include "player.h"

player::player(float x, float y, int t_size) : abstract_renderer(sf::Triangles, 6, true), x(x), y(y), t_size(t_size)
{
}

void player::tick(sf::Time delta_time)
{
    x += 1.f;

    va[0].position = sf::Vector2f(x, y);
    va[1].position = sf::Vector2f(x + t_size, y);
    va[2].position = sf::Vector2f(x, y + t_size);
    va[3].position = sf::Vector2f(x, y + t_size);
    va[4].position = sf::Vector2f(x + t_size, y);
    va[5].position = sf::Vector2f(x + t_size, y + t_size);
}