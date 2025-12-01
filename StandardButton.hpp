#pragma once
#include <SFML/Graphics.hpp>

class StandardButton : public sf::RectangleShape
{
public:
	StandardButton() : sf::RectangleShape(sf::Vector2f(450, 450))
	{
		standard = new sf::Texture;
		setPosition(sf::Vector2f(525, 500));
		standard->loadFromFile("Standard.png");
		setTexture(standard);
	}
	~StandardButton() { delete standard; }

private:
	sf::Texture* standard;
};