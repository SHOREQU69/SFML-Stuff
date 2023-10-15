#include "grid.h"

grid::grid(int tile_size) : abstract_renderer(sf::Triangles, 6, true), tile_size(tile_size)
{
    int amount = WINDOW_SIZE / tile_size;

    va.resize(amount * amount * va.getVertexCount());

    //hover initialisation and color setting
    selected_tile = sf::VertexArray(sf::Triangles, 6);

    selected_tile[0].color = sf::Color(200, 200, 200, 100);
    selected_tile[1].color = sf::Color(200, 200, 200, 100);
    selected_tile[2].color = sf::Color(200, 200, 200, 100);
    selected_tile[3].color = sf::Color(200, 200, 200, 100);
    selected_tile[4].color = sf::Color(200, 200, 200, 100);
    selected_tile[5].color = sf::Color(200, 200, 200, 100);

    // generates an empty map (marked by 0 values)
    map = new int *[amount];

    for (int i = 0; i < amount; i++)
    {
        map[i] = new int[amount];

        for (int j = 0; j < amount; j++)
            map[i][j] = 0;
    }

    // empty tile is represented by the color (180, 180, 180)
    init(EMPTY_TILE_COLOR);

    // set the position to all the vertices
    for (int i = 0; i < amount; i++)
    {
        for (int j = 0; j < amount; j++)
        {
            // one tile is a quad made out of 2 triangles (6 vertices)
            sf::Vertex *v = &va[(i + j * amount) * 6];

            v[0].position = sf::Vector2f(i * tile_size, j * tile_size);
            v[1].position = sf::Vector2f((i + 1) * tile_size, j * tile_size);
            v[2].position = sf::Vector2f(i * tile_size, (j + 1) * tile_size);
            v[3].position = sf::Vector2f(i * tile_size, (j + 1) * tile_size);
            v[4].position = sf::Vector2f((i + 1) * tile_size, j * tile_size);
            v[5].position = sf::Vector2f((i + 1) * tile_size, (j + 1) * tile_size);
        }
    }
}

void grid::print_map()
{
    for (int i = 0; i < WINDOW_SIZE / tile_size; i++)
    {
        for (int j = 0; j < WINDOW_SIZE / tile_size; j++)
        {
            std::cout << map[j][i] << " ";
        }

        std::cout << "\n";
    }
}

sf::Vertex *grid::get_tile_at_pos(sf::Vector2i pos)
{
    int amount = WINDOW_SIZE / tile_size;
    return &va[(pos.x + pos.y * amount) * 6];
}

bool grid::set_tile_at_pos(sf::Vector2i pos, int new_type, int clamped)
{
    // error checking
    if (pos.x < 0 || pos.x >= WINDOW_SIZE)
        return false;

    if (pos.y < 0 || pos.y >= WINDOW_SIZE)
        return false;

    if (clamped && (pos.x >= WINDOW_SIZE / tile_size || pos.y >= WINDOW_SIZE / tile_size))
        return false;

    int amount = WINDOW_SIZE / tile_size;

    // if clamped, the position is considered to be a valid tile map position
    if (clamped)
    {
        // sets color based on type
        if (new_type == 0)
        {
            sf::Vertex *v = &va[(pos.x + pos.y * amount) * 6];

            for (int i = 0; i < 6; i++)
                v[i].color = EMPTY_TILE_COLOR;
        }
        else
        {
            sf::Vertex *v = &va[(pos.x + pos.y * amount) * 6];

            for (int i = 0; i < 6; i++)
                v[i].color = FULL_TILE_COLOR;
        }

        return true;
    }

    // gets the given tile map location based on the input location
    int map_x = pos.x / tile_size;
    int map_y = pos.y / tile_size;

    map[map_x][map_y] = new_type;

    // sets color based on type
    if (new_type == 0)
    {
        sf::Vertex *v = &va[(map_x + map_y * amount) * 6];

        for (int i = 0; i < 6; i++)
            v[i].color = EMPTY_TILE_COLOR;
    }
    else
    {
        sf::Vertex *v = &va[(map_x + map_y * amount) * 6];

        for (int i = 0; i < 6; i++)
            v[i].color = FULL_TILE_COLOR;
    }

    return true;
}

void grid::tick(sf::Vector2i mouse_pos)
{
    //sets the position of the hover to the tile the mouse is over
    sf::Vector2f mouse_map_pos = sf::Vector2f(mouse_pos.x / tile_size, mouse_pos.y / tile_size);

    mouse_map_pos.x *= tile_size;
    mouse_map_pos.y *= tile_size;

    selected_tile[0].position = sf::Vector2f(mouse_map_pos.x, mouse_map_pos.y);
    selected_tile[1].position = sf::Vector2f(mouse_map_pos.x + tile_size, mouse_map_pos.y);
    selected_tile[2].position = sf::Vector2f(mouse_map_pos.x, mouse_map_pos.y + tile_size);
    selected_tile[3].position = sf::Vector2f(mouse_map_pos.x, mouse_map_pos.y + tile_size);
    selected_tile[4].position = sf::Vector2f(mouse_map_pos.x + tile_size, mouse_map_pos.y);
    selected_tile[5].position = sf::Vector2f(mouse_map_pos.x + tile_size, mouse_map_pos.y + tile_size);
}

bool add = false;
bool del = false;

void grid::modify_grid(sf::Event event, sf::Vector2i mouse_pos)
{
    if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
        add = true;
    else if(event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
        add = false;

    if (event.mouseButton.button == sf::Mouse::Right && event.type == sf::Event::MouseButtonPressed)
        del = true;
    else if(event.mouseButton.button == sf::Mouse::Right && event.type == sf::Event::MouseButtonReleased)
        del = false;

    if(add)
        set_tile_at_pos(mouse_pos, 1, 0);
    if(del)
        set_tile_at_pos(mouse_pos, 0, 0);
}