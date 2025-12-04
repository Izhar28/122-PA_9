// This Header File contains a class that randomizes the location of the chess pieces.
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
