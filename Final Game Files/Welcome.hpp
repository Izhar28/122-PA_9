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