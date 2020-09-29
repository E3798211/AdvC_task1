
#include <iostream>
#include <SFML/Graphics.hpp>
#include "win_manager.h"

#include "counting_int.h"


int main()
{
    WinManager wm(800, 600, "Sort!");
    wm.run();
}

