#include "Board.hpp"

Board::Board()
{
}

Board::~Board()
{
}

void Board::initializeBoard(Mode m)
{
	int color = 0;
	if (m == Standard)
	{
		for (int i = 0; i < 8; ++i)
		{
			board[i]->setColumn((char)65 + i);
			board[i]->setRow(1);
			if (color == 0)
			{
				board[i]->setColor(sf::Color::Black);

				color == 1;
			}
			else if (color == 1)
			{
				board[i]->setColor(sf::Color::White);
				color == 0;
			}
		}
	}
	if (m == Random)
	{

	}
}
