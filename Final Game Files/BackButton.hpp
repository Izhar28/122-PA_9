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