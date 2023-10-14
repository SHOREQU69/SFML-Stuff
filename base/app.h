#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <string>

#define FPS 60

/*
    Main class to handle all the app logic such as tick, render and events.
*/

class app
{
private:
    //window parameters
    unsigned int size;
    std::string name;

public:
    static sf::RenderWindow *window;

    app(unsigned int size, std::string name);
    ~app();
    //process events
    void events();
    //get the position of the mouse relative to the window
    sf::Vector2i get_mouse_pos();
    void tick(sf::Time delta_time);
    void render();
    //main function
    void run();
};

#endif