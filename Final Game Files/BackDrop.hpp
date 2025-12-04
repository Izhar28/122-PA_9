#pragma once
#include <SFML/Graphics.hpp>

class BackDrop : public sf::RectangleShape
{
public:
	BackDrop() : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		setPosition(sf::Vector2f(0, 0));
	}

	BackDrop(sf::Texture& BackDropTexture) : sf::RectangleShape(sf::Vector2f(1000, 1000))
	{
		setTexture(&BackDropTexture);
		setPosition(sf::Vector2f(0, 0));
	}

	void Wins(int const state, sf::Texture& whiteWins, sf::Texture& blackWins)
	{
		if (state == 2) // Black wins
		{
			setTexture(&blackWins);
		}
		else // White Wins
		{
			setTexture(&whiteWins);
		}
	}

	void underConstruction(sf::Texture& underConstruction)
	{
		setTexture(&underConstruction);
	}

	void Normal(sf::Texture& BackDropTexture)
	{
		setTexture(&BackDropTexture);
	}

	~BackDrop() {}
};