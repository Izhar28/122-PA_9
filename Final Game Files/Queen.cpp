#include "Queen.hpp"


Queen::Queen() : Piece()
{
	color = "Blank";
}

Queen::Queen(std::string newColor) : Piece()
{
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BlueQueen);
	}
	else if (newColor == "White")
	{
		setTexture(&TanQueen);
	}
}

Queen::~Queen()
{ 
}

void Queen::movementSquares(Board& gameBoard)
{
	int c = (int)column + 1, r = row + 1;

	while (c < 8 && r < 8 && !gameBoard.getSquares((ChessCol)c, r)->getOccupied())
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
		c++;
		r++;
	}

	if (c < 8 && r < 8 && gameBoard.getSquares((ChessCol)c, r)->getOccupied() && gameBoard.getSquares((ChessCol)c, r)->getOccupiedColor() != color)
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
	}

	c = (int)column - 1;
	r = row + 1;

	while (c >= 0 && r < 8 && !gameBoard.getSquares((ChessCol)c, r)->getOccupied())
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
		c--;
		r++;
	}

	if (c >= 0 && r < 8 && gameBoard.getSquares((ChessCol)c, r)->getOccupied() && gameBoard.getSquares((ChessCol)c, r)->getOccupiedColor() != color)
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
	}

	c = (int)column + 1;
	r = row - 1;

	while (c < 8 && r >= 0 && !gameBoard.getSquares((ChessCol)c, r)->getOccupied())
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
		c++;
		r--;
	}

	if (c < 8 && r >= 0 && gameBoard.getSquares((ChessCol)c, r)->getOccupied() && gameBoard.getSquares((ChessCol)c, r)->getOccupiedColor() != color)
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
	}


	c = (int)column - 1;
	r = row - 1;

	while (c >= 0 && r >= 0 && !gameBoard.getSquares((ChessCol)c, r)->getOccupied())
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
		c--;
		r--;
	}

	if (c >= 0 && r >= 0 && gameBoard.getSquares((ChessCol)c, r)->getOccupied() && gameBoard.getSquares((ChessCol)c, r)->getOccupiedColor() != color)
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
	}

	// right
	for (int i = (int)column + 1; i < 8; ++i)
	{
		if (!gameBoard.getSquares((ChessCol)i, row)->getOccupied())
		{
			gameBoard.getSquares((ChessCol)i, row)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares((ChessCol)i, row)->getOccupiedColor() != color)
			{
				gameBoard.getSquares((ChessCol)i, row)->setState(ACTIVE);
			}
			break;
		}
	}

	// left
	for (int i = (int)column - 1; i >= 0; --i)
	{
		if (!gameBoard.getSquares((ChessCol)i, row)->getOccupied())
		{
			gameBoard.getSquares((ChessCol)i, row)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares((ChessCol)i, row)->getOccupiedColor() != color)
			{
				gameBoard.getSquares((ChessCol)i, row)->setState(ACTIVE);
			}
			break;
		}
	}

	// down
	for (int j = row + 1; j < 8; ++j)
	{
		if (!gameBoard.getSquares(column, j)->getOccupied())
		{
			gameBoard.getSquares(column, j)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares(column, j)->getOccupiedColor() != color)
			{
				gameBoard.getSquares(column, j)->setState(ACTIVE);
			}
			break;
		}
	}

	// up
	for (int j = row - 1; j >= 0; --j)
	{
		if (!gameBoard.getSquares(column, j)->getOccupied())
		{
			gameBoard.getSquares(column, j)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares(column, j)->getOccupiedColor() != color)
			{
				gameBoard.getSquares(column, j)->setState(ACTIVE);
			}
			break;
		}
	}
}