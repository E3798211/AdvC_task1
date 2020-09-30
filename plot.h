
#ifndef   PLOT_H_INCLUDED
#define   PLOT_H_INCLUDED

#include <SFML/Graphics.hpp>

class Plot : public sf::Sprite
{
private:
    sf::Image       image;
    sf::Texture     texture;
public:
    Plot(const sf::Vector2u &size) noexcept 
    {
        image.create(size.x, size.y);
        texture.loadFromImage(image);
        setTexture(texture, true);
    }
    void putPoints(const std::vector<sf::Vector2i> points,
              const sf::Color &c) noexcept;
};

#endif // PLOT_H_INCLUDED

