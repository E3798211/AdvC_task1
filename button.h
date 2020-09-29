
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
    /* Performs necessary initializations */
    explicit Button() noexcept
        : bound (sf::Vector2f(150.0, 40.0))
    {
        bound.setFillColor(sf::Color::Magenta);
        text.move(10.0, 5.0);
    }
    explicit Button(const std::string& name, const sf::Font &font) noexcept
        : Button()
    {
        setText(name, font);
    }

    void setText(const std::string& name, const sf::Font &font) noexcept {
        text.setString(name);
        text.setFont(font);
    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        target.draw(bound, states);
        target.draw(text, states);
    }
};

#endif // BUTTON_H_INCLUDED

