#ifndef PLAYER_H
#define PLAYER_H

#include "../base/abstract_renderer.h"

class Player: public AbstractRenderer
{
private:
    int x, y;
    int t_size;

public:
    Player(int x, int y, int t_size);
    ~Player();
    void init(sf::Color color) override;
    void tick(sf::Time delta_time);
};

#endif