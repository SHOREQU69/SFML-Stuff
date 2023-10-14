#ifndef PLAYER_H
#define PLAYER_H

#include "../base/abstract_renderer.h"

/*
    Generic player class to add more interaction to the project
*/

class player: public abstract_renderer
{
private:
    float x, y;
    int t_size;

public:
    player(float x, float y, int t_size);
    void tick(sf::Time delta_time);
};

#endif