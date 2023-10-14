#ifndef ABSTRACT_RENDERER_H
#define ABSTRACT_RENDERER_H

#include <SFML/Graphics.hpp>

/*
    Handles all rendering stuff to the screen
*/

class AbstractRenderer
{
protected:
    //holds the vertex data
    sf::VertexArray va;
    //checks if the object should be rendered or not
    bool active;

public:
    AbstractRenderer(sf::PrimitiveType type, size_t array_size, bool active);
    //the initialisation should be handled by each different object type
    virtual void init(sf::Color color) = 0;
    //handles rendering. Normally, the vertex array is simply rendered
    virtual void render(sf::RenderWindow *window);
};

#endif