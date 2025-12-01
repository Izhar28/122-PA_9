#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Welcome.hpp"
#include "BackDrop.hpp"
#include "RandomizeButton.hpp"
#include "StandardButton.hpp"
#include "UndoButton.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Checkers-Adjacent");
    
    Welcome WelcomeBackDrop;
    BackDrop Back;
    RandomizeButton Randomized;
    StandardButton Standard;
    UndoButton Undo;

    Mode mode;
    Board B;
    sf::Vector2f mouse;
    int state = 0;

    while (window.isOpen())
    {
        mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!state)
        {
            window.clear(sf::Color::Black);
            window.draw(WelcomeBackDrop);
            window.draw(Randomized);
            window.draw(Standard);
        }
        if (state)
        {
            window.clear(sf::Color::Black);
            window.draw(Back);
            B.Draw(window);
            window.draw(Undo);
        }

        if (Standard.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mode = STANDARD;
                window.clear(sf::Color::Black);
                window.draw(Back);
                B.Draw(window);
                window.draw(Undo);
                state = 1;
            }
        }
        if (Randomized.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mode = RANDOM;
                window.clear(sf::Color::Black);
                window.draw(Back);
                B.Draw(window);
                window.draw(Undo);
                state = 1;
            }
        }
        window.display();
    }

	return 0;
}