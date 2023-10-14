#include "abstract_renderer.h"

AbstractRenderer::AbstractRenderer(sf::PrimitiveType type, size_t array_size, bool active): 
active(active)
{
    va.setPrimitiveType(type);
    va.resize(array_size);
}

void AbstractRenderer::render(sf::RenderWindow* window)
{
    window->draw(va);
}