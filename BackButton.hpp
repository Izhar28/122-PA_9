#pragma once
#include <SFML/Graphics.hpp>

class BackButton : public sf::RectangleShape
{
public:
	BackButton() : sf::RectangleShape(sf::Vector2f(200, 90))
	{
		back = new sf::Texture;
		setPosition(sf::Vector2f(35, 5));
		back->loadFromFile("BackButton.png");
		setTexture(back);
	}
	~BackButton() { delete back; }
private:
	sf::Texture* back;
};