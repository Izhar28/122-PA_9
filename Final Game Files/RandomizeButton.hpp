// This Header File contains a class that randomizes the location of the chess pieces. This class also 
// prints the Randomize button to the main menu for the player to click on when deciding which style of chess to play.
#pragma once
#include <SFML/Graphics.hpp>

class RandomizeButton : public sf::RectangleShape
{
public:
	RandomizeButton() : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		setPosition(sf::Vector2f(25, 500));
	}

	RandomizeButton(sf::Texture& random) : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		setTexture(&random);
		setPosition(sf::Vector2f(25, 500));
	}

	~RandomizeButton() {}

};

