
#include "win_manager.h"

#include <iostream>

// Need explicit instantiation here...
template void sorts::bubble(std::vector<CountingInt>&);
void setBubblesort(WinManager *wm) noexcept {
    if (wm) {
        wm->sort = sorts::bubble<CountingInt>;
    }
}

template void sorts::stdsort(std::vector<CountingInt>&);
void setStdsort(WinManager *wm) noexcept {
    if (wm) {
        wm->sort = sorts::stdsort<CountingInt>;
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
    b.setOnPress(setBubblesort);
}

bool WinManager::run() noexcept {
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
                return true;
            }
            if (e.type == sf::Event::MouseButtonPressed) {
                if (isButtonPressed(b, sf::Mouse::getPosition(window))) {
                    std::cout << "old value = " << (void*)sort << "\n";
                    b.doPressAction(this);
                    std::cout << "new value = " << (void*)sort << "\n";
                }
            }
        }

        window.clear(sf::Color::Red);
        window.draw(b);
        window.display();

        sort = nullptr;
    }
    return false;
}


