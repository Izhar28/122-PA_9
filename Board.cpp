#include "Board.hpp"

Board::Board()
{
	initializeBoard();
}

Board::~Board()
{
}

void Board::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape* This;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			This = &squares[i][j];
			window.draw(*This);
		}
	}
}

void Board::initializeBoard()
{
	sf::Texture* whiteTex = new sf::Texture();
	sf::Texture* blackTex = new sf::Texture();
	whiteTex->loadFromFile("C:/Users/Owner/Downloads/white.png");
	blackTex->loadFromFile("C:/Users/Owner/Downloads/black.png");

	sf::Vector2f Position = { 100, 300 };
	int color = 0;
	for (int i = 0; i < 8; ++i)
	{
		Position.y = 100;
		for (int j = 0; j < 8; ++j)
		{
			squares[i][j].setColumn((char)65 + i);
			squares[i][j].setRow(j);
			squares[i][j].setPos(Position);
			squares[i][j].setFillColor(sf::Color::White);
			Position.y += 100;

			if (i % 2 == 0)
			{
				if (color == 0)
				{
					squares[i][j].setTexture(blackTex);
					color = 1;
				}
				else if (color == 1)
				{
					squares[i][j].setTexture(whiteTex);
					color = 0;
				}
			}
			else
			{
				if (color == 0)
				{
					squares[i][j].setTexture(whiteTex);
					color = 1;
				}
				else if (color == 1)
				{
					squares[i][j].setTexture(blackTex);
					color = 0;
				}
			}
		}
		Position.x += 100;
	}
}
