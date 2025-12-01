#pragma once
#include <SFML/Graphics.hpp>

class UndoButton : public sf::RectangleShape
{
public:
	UndoButton() : sf::RectangleShape(sf::Vector2f(225, 90))
	{
		undo= new sf::Texture;
		setPosition(sf::Vector2f(800, 5));
		undo->loadFromFile("Undo.png");
		setTexture(undo);
	}
	~UndoButton() { delete undo; }
private:
	sf::Texture* undo;
};