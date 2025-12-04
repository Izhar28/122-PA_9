// This Header File contains the actual code and functions that print the board and deactivates the squares that are considered active.
#include "Board.hpp"

Board::Board()
{
	squares.resize(8, std::vector<Square>(8));
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

Square* Board::getSquares(ChessCol column, int row)
{
	return &squares[(int)column][row];
}

void Board::deactivateSquares()
{
	for (int i = 0; i < 8; ++i) // columns
	{
		for (int j = 0; j < 8; ++j)
		{
			if (squares[i][j].getState() == ACTIVE) squares[i][j].setState(IDLE);
		}
	}
}

void Board::initializeBoard()
{
	sf::Vector2f Position = { 100, 300 };
	int color = 0;
	for (int i = 0; i < 8; ++i) // columns
	{
		Position.y = 100;
		for (int j = 0; j < 8; ++j)  // rows
		{
			squares[i][j].setColumn((ChessCol)i);
			squares[i][j].setRow(j);
			squares[i][j].setPos(Position);
			squares[i][j].setFillColor(sf::Color::White);
			Position.y += 100;

			if (i % 2 == 1)
			{
				if (color == 0)
				{
					squares[i][j].setColor("Black");
					squares[i][j].setState(IDLE);
					color = 1;
				}
				else if (color == 1)
				{
					squares[i][j].setColor("White");
					squares[i][j].setState(IDLE);
					color = 0;
				}
			}
			else
			{
				if (color == 0)
				{
					squares[i][j].setColor("White");
					squares[i][j].setState(IDLE);
					color = 1;
				}
				else if (color == 1)
				{
					squares[i][j].setColor("Black");
					squares[i][j].setState(IDLE);
					color = 0;
				}
			}
		}
		Position.x += 100;
	}
}

