#include "abstract_renderer.h"

abstract_renderer::abstract_renderer(sf::PrimitiveType type, size_t array_size, bool active): 
active(active)
{
    va.setPrimitiveType(type);
    va.resize(array_size);
}

abstract_renderer::~abstract_renderer()
{
}

void abstract_renderer::init(sf::Color color)
{
    for (size_t i = 0; i < va.getVertexCount(); i++)
        va[i].color = color;
}

void abstract_renderer::render(sf::RenderWindow* window)
{
    window->draw(va);
}

void abstract_renderer::setActive(bool active)
{
    this->active = active;
}