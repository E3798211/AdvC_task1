
#include "win_manager.h"
#include <iostream>

static void inc(WinManager *wm) {
    if (wm) {
        wm->value++;
    }
}

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
    b.setOnPress(inc);
}

bool WinManager::run() noexcept {


    value = 0;


    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
                return true;
            }
            if (e.type == sf::Event::MouseButtonPressed) {
                if (isButtonPressed(b, sf::Mouse::getPosition(window))) {
                    b.doPressAction(this);
                    std::cout << "new value = " << value << "\n";
                }
            }
        }

        window.clear(sf::Color::Red);
        window.draw(b);
        window.display();
    }
    return false;
}


