
#ifndef   WIN_MANAGER_H_INCLUDED
#define   WIN_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "button.h"

class WinManager
{
private:
    sf::RenderWindow window;

    sf::Font font;
    Button b;

public:
    int value;
    explicit WinManager(int width, int height, const std::string &name);

    /* Returns whether user has closed the window himself */
    bool run() noexcept;
};

#endif // WIN_MANAGER_H_INCLUDED

