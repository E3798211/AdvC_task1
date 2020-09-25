
#include <iostream>
#include <SFML/Graphics.hpp>

#include "counting_int.h"
#include "button.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Font font;
    if (!font.loadFromFile("UbuntuMono-B.ttf")) {
        std::cout << "Wow!\n";
        return 1;
    }

    Button b1("Hello", font);
    b1.move(40, 40);
    Button b2("Merge", font);
    b2.move(40, 90);
    Button b3("Mergesort", font);
    b3.move(40, 140);


    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::Red);
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.display();
    }
}

