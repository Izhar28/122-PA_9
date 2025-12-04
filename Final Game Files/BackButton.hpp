// This Header file contains the class for the back button. The back button will allow the player to go back to 
// main menu if they chose the wrong option
#pragma once
#include <SFML/Graphics.hpp>

class BackButton : public sf::RectangleShape
{
public:
	BackButton() : sf::RectangleShape(sf::Vector2f(200, 90))
	{
		setPosition(sf::Vector2f(35, 5));
	}

	BackButton(sf::Texture& back) : sf::RectangleShape(sf::Vector2f(200, 90))
	{
		setTexture(&back);
		setPosition(sf::Vector2f(35, 5));
	}

	~BackButton() {}

};

