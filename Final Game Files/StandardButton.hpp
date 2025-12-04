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