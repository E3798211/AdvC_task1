
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
    
    buttons[BUTTON_SET_BUBBLESORT].setText("Bubblesort", font);
    buttons[BUTTON_SET_BUBBLESORT].move(40.0, 50.0);
    buttons[BUTTON_SET_BUBBLESORT].setOnPress(setBubblesort);

    buttons[BUTTON_SET_STDSORT].setText("Stdsort", font);
    buttons[BUTTON_SET_STDSORT].move(40.0, 100.0);
    buttons[BUTTON_SET_STDSORT].setOnPress(setStdsort);
}

void WinManager::processMouseKeyPress() noexcept {
    sf::Vector2i cursor = sf::Mouse::getPosition(window);
    for (auto &b : buttons)
        if (isButtonPressed(b, cursor))
            b.doPressAction(this);
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
                processMouseKeyPress();
                std::cout << "sort = " << (void *)sort << "\n";
            }
        }

        window.clear(sf::Color::Red);
        for (int i = 0; i < NBUTTONS; i++)
            window.draw(buttons[i]);
        window.display();
    }
    return false;
}

