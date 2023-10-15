#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "../base/abstract_renderer.h"

/*
    Handles the grid of tiles

    Grid tile types: 0 for empty tile, 1 for full tile
*/

#define EMPTY_TILE_COLOR sf::Color::Black
#define FULL_TILE_COLOR sf::Color(80, 45, 0)

class grid : public abstract_renderer
{
private:
    const int WINDOW_SIZE = 800;
    // size will be read from the command line and should be divisible by the size of the window
    int tile_size;
    // tile map represented as an integer matrix
    int **map;

public:
    //a tile sized quad that shows the tile the mouse hovers over
    sf::VertexArray selected_tile;
    grid(int tile_size);
    void tick(sf::Vector2i mouse_pos);
    // basic debug
    void print_map();
    // returns a pointer that contains the 6 vertices that compose the tile at the given location
    sf::Vertex *get_tile_at_pos(sf::Vector2i pos);
    /*
    sets the tile at the given location to the given type. if the clamped param is 0, the position
    is considered to not be an actual map position and is divided by the tile size
    */
    bool set_tile_at_pos(sf::Vector2i pos, int new_type, int clamped);
    //based on input events, modify the map accordingly
    void modify_grid(sf::Event event, sf::Vector2i mouse_pos);
};

#endif