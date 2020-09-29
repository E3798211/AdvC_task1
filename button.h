
#ifndef   BUTTON_H_INCLUDED
#define   BUTTON_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class WinManager;

using action_t = void (*)(WinManager*);

class Button : public sf::RectangleShape
{
private:
    sf::Text    text;
    action_t on_press;

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
        , on_press      (nullptr)
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

    // Returns previous value
    action_t setOnPress(action_t new_on_press) noexcept {
        action_t old = on_press;
        on_press = new_on_press;
        return old;
    }

    void doPressAction(WinManager *wm) {
        on_press(wm);
    }

    friend bool isButtonPressed(const Button &b, const sf::Vector2i &cursor);
};

bool isButtonPressed(const Button &b, const sf::Vector2i &cursor);

#endif // BUTTON_H_INCLUDED

