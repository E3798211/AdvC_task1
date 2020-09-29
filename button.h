
#ifndef   BUTTON_H_INCLUDED
#define   BUTTON_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class Button : public sf::RectangleShape
{
private:
    sf::Text    text;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // Note: const to object, not reference. This allows to change
        // the virtual functions called
        target.draw(static_cast<const RectangleShape>(*this), states);

        // Move text to the rectangle's position
        states.transform *= getTransform();
        target.draw(text, states);
    }
public:
    /* Performs necessary initializations */
    explicit Button() noexcept
        : RectangleShape(sf::Vector2f(150.0, 40.0))
    {
        setFillColor(sf::Color::Magenta);
        text.move(10.0, 0.0);
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

    friend bool isButtonPressed(const Button &b, const sf::Vector2i &cursor);
};

bool isButtonPressed(const Button &b, const sf::Vector2i &cursor);

#endif // BUTTON_H_INCLUDED

