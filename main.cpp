#include <SFML/Graphics.hpp>
#include <stack>
#include "Board.hpp"
#include "Welcome.hpp"
#include "BackDrop.hpp"
#include "RandomizeButton.hpp"
#include "StandardButton.hpp"
#include "UndoButton.hpp"
#include "Move.hpp"
#include "BackButton.hpp"

int main(void)
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({ 1000, 1000 }), "Checkers-Adjacent");
    std::stack<Move> moves;

    Welcome WelcomeBackDrop;
    BackDrop Back;
    RandomizeButton Randomized;
    StandardButton Standard;
    UndoButton Undo;
    BackButton BackButton;

    Mode mode;
    Board B;
    sf::Vector2f mouse;
    int state = 0;

    while (window->isOpen())
    {
        mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }

        if (!state)
        {
            window->clear(sf::Color::Black);
            window->draw(WelcomeBackDrop);
            window->draw(Randomized);
            window->draw(Standard);
        }
        else if (state)
        {
            window->clear(sf::Color::Black);
            window->draw(Back);
            B.Draw(*window);
            window->draw(Undo);
            window->draw(BackButton);

            if (Undo.getGlobalBounds().contains(mouse)) // Undo Move
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    if (!moves.empty()) moves.pop();
                }
            }
            if (BackButton.getGlobalBounds().contains(mouse)) // Back to Main menu
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    state = 0;
                    window->clear(sf::Color::Black);
                    window->draw(WelcomeBackDrop);
                    window->draw(Randomized);
                    window->draw(Standard);
                    window->draw(BackButton);
                }
            }
        }

        if (state == 0 && Standard.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mode = STANDARD;
                window->clear(sf::Color::Black);
                window->draw(Back);
                B.Draw(*window);
                window->draw(Undo);
                window->draw(BackButton);
                state = 1;
            }
        }
        if (state == 0 && Randomized.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mode = RANDOM;
                window->clear(sf::Color::Black);
                window->draw(Back);
                B.Draw(*window);
                window->draw(Undo);
                window->draw(BackButton);
                state = 1;
            }
        }
        window->display();
    }

    delete window;
	return 0;
}