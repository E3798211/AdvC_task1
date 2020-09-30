
#include <algorithm>
#include "plot.h"

/* Returns already rounded to int */
static inline int norm_to(int xmax, int x, float lowbound, float highbound) {
    return xmax * (x - lowbound) / (highbound - lowbound);
}

void Plot::putPoints(const std::vector<sf::Vector2i> points,
                const sf::Color &c) noexcept {
    float xmax = -1, xmin = 100000;
    float ymax = -1, ymin = 100000;
    for (auto &p : points) {
        if (p.x > xmax) xmax = p.x;
        if (p.x < xmin) xmin = p.x;
        if (p.y > ymax) ymax = p.y;
        if (p.y < ymin) ymin = p.y;
    }
    /* Sorry, no anti-aliasing */
    sf::Vector2u size = image.getSize();
    for (auto &p : points) {
        int x = norm_to(size.x, p.x, xmax, xmin);
        int y = norm_to(size.y, p.y, ymax, ymin);
        // The (0,0) is in the right down corner
        image.setPixel(size.x - x, y, c);
    }

    texture.update(image);
}

