
#include "button.h"

bool isButtonPressed(const Button &b, const sf::Vector2i &cursor) {
    auto left_up = b.getPosition();
    auto right_down = left_up + b.getSize();

    if (cursor.x < left_up.x || right_down.x < cursor.x)
        return false;
    if (cursor.y < left_up.y || right_down.y < cursor.y)
        return false;
    return true;
}

