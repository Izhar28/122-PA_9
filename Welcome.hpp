#pragma once
#include <SFML/Graphics.hpp>

class Welcome : public sf::RectangleShape
{
public:
	Welcome() : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		WelcomeBackDrop = new sf::Texture;
		setPosition(sf::Vector2f(0, 0));
		WelcomeBackDrop->loadFromFile("WelcomeBackDrop.png");
		setTexture(WelcomeBackDrop);
	}
	~Welcome() { delete WelcomeBackDrop; }

private:
	sf::Texture *WelcomeBackDrop;
};