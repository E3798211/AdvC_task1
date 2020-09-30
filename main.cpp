
#include <iostream>
#include <SFML/Graphics.hpp>

#include "win_manager.h"

int main()
{
    WinManager wm(800, 600, "Sort!");
    wm.run();
}

