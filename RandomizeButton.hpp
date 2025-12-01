#pragma once
#include <SFML/Graphics.hpp>

class RandomizeButton : public sf::RectangleShape
{
public:
	RandomizeButton() : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		random = new sf::Texture;
		setPosition(sf::Vector2f(25, 500));
		random->loadFromFile("Random.png");
		setTexture(random);
	}
	~RandomizeButton() { delete random; }

private:
	sf::Texture* random;
};