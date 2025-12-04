// This cpp File contains all the code that relates to the Rook piece in the game of chess. 
// This File contains the code to determine the color of the piece and the movement pattern the Rook has in a regular game.
#include "Rook.hpp"

Rook::Rook() : Piece()
{
	color = "Blank";
}

Rook::Rook(std::string newColor) : Piece()
{
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BlueRook);
	}
	else if (newColor == "White")
	{
		setTexture(&TanRook);
	}
}

Rook::~Rook()
{ 
}

void Rook::movementSquares(Board& gameBoard)
{
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
