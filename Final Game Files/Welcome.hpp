// This Header File contains a class that contains the welcome screen when you first load up the game.
// This also sets the the texture of the background to be the welcome screen when ran.
#pragma once
#include <SFML/Graphics.hpp>

class Welcome : public sf::RectangleShape
{
public:
	Welcome() : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		setPosition(sf::Vector2f(0, 0));
	}

	Welcome(sf::Texture& WelcomeBackDrop) : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		setTexture(&WelcomeBackDrop);
		setPosition(sf::Vector2f(0, 0));
	}

	~Welcome() {}

};
