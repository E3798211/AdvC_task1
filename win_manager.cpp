
#include "win_manager.h"
#include <iostream>

WinManager::WinManager(int width, int height, const std::string &name)
    : window(sf::VideoMode(width, height), name)
{
    // TODO: fix error recovery
    if (!font.loadFromFile("UbuntuMono-B.ttf")) {
        std::cout << "Wow!\n";
        return;
    }
    
    b.setText("Hello", font);
    b.move(40, 40);
}

bool WinManager::run() noexcept {
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed) {
                window.close();
                return true;
            }

        window.clear(sf::Color::Red);
        window.draw(b);
        window.display();
    }
    return false;
}


