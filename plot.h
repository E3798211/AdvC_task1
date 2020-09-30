
#ifndef   PLOT_H_INCLUDED
#define   PLOT_H_INCLUDED

#include <SFML/Graphics.hpp>

class Plot : public sf::Sprite
{
private:
    sf::Image       image;
    sf::Texture     texture;

    sf::Text        label;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(static_cast<const sf::Sprite>(*this), states);
        
        states.transform *= getTransform();
        target.draw(label, states);
    }

public:
    Plot(const sf::Vector2u &size) noexcept 
    {
        image.create(size.x, size.y);
        texture.loadFromImage(image);
        setTexture(texture, true);
    }

    void setLabel(const sf::Text &lbl) noexcept;

    void putPoints(const std::vector<sf::Vector2i> points,
                   const sf::Color &c = sf::Color::White) noexcept;
    void clear() noexcept;
};

#endif // PLOT_H_INCLUDED

