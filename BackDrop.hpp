#pragma once
#include <SFML/Graphics.hpp>

class BackDrop : public sf::RectangleShape
{
public:
	BackDrop() : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		BackDropTexture = new sf::Texture;
		setPosition(sf::Vector2f(0, 0));
		BackDropTexture->loadFromFile("BackDrop.png");
		setTexture(BackDropTexture);
	}
	~BackDrop() { delete BackDropTexture; }

private:
	sf::Texture* BackDropTexture;
};