
#ifndef   WIN_MANAGER_H_INCLUDED
#define   WIN_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

#include "button.h"
#include "sort.hpp"
#include "counting_int.h"

class WinManager
{
private:
    sf::RenderWindow window;

    sf::Font font;
    Button b;

    sorts::sort_t<CountingInt> sort;
public:
    explicit WinManager(int width, int height, const std::string &name);

    /* Returns whether user has closed the window himself */
    bool run() noexcept;

    friend void setBubblesort(WinManager *wm) noexcept;
    friend void setStdsort(WinManager *wm) noexcept;
};

#endif // WIN_MANAGER_H_INCLUDED

