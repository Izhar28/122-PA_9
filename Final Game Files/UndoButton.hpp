// This Header file contains the class for the Undo button. The Undo button will allow the player to undo a 
// decision they made in game and return them to a previous move
#pragma once
#include <SFML/Graphics.hpp>

class UndoButton : public sf::RectangleShape
{
public:
	UndoButton() : sf::RectangleShape(sf::Vector2f(225, 90))
	{
		setPosition(sf::Vector2f(800, 5));
	}

	UndoButton(sf::Texture& undo) : sf::RectangleShape(sf::Vector2f(225, 90))
	{
		setTexture(&undo);
		setPosition(sf::Vector2f(800, 5));
	}

	~UndoButton() {}

};
