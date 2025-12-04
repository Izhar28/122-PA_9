// This Header File contains the Standard button class. This class gives the option to the player to run a 
// standard game of chess. This class also prints the standard button to the main menu for the player to click on.
#pragma once
#include <SFML/Graphics.hpp>

class StandardButton : public sf::RectangleShape
{
public:
	StandardButton() : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		setPosition(sf::Vector2f(525, 500));
	}

	StandardButton(sf::Texture& standard) : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		setTexture(&standard);
		setPosition(sf::Vector2f(525, 500));
	}

	~StandardButton() {}


};
