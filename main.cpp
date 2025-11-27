#include <SFML/Graphics.hpp>
#include "Board.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Strange Chess");
    Board B;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        B.Draw(window);
        window.display();
    }
	return 0;
}