
#include <iostream>
#include <SFML/Graphics.hpp>

#include "counting_int.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.display();
    }
}

