
#ifndef   BUTTON_H_INCLUDED
#define   BUTTON_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape bound;
    sf::Text           text;
public:
    /* Many parameters cannot be set... */
    explicit Button(const std::string& name, const sf::Font &font)
        : bound (sf::Vector2f(150., 40.))
        , text  (name, font, 20)
    {
        bound.setFillColor(sf::Color::Magenta);
        text.move(10.0, 5.0);
    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        target.draw(bound, states);
        target.draw(text, states);
    }
};

#endif // BUTTON_H_INCLUDED

