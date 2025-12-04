#include "Pawn.hpp"

Pawn::Pawn() : Piece()
{
	color = "Blank";
	moveCount = 0;
}

Pawn::Pawn(std::string newColor) : Piece()
{
	moveCount = 0;
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BluePawn);
	}
	else if (newColor == "White")
	{
		setTexture(&TanPawn);
	}
}

Pawn::~Pawn()
{  
}

void Pawn::addMove()
{ 
	++moveCount; 
}

void Pawn::resetMove()
{
	moveCount = 0;
}

void Pawn::movementSquares(Board& gameBoard)
{
	int i = (int)column, direction = (color == "Black") ? -1 : 1;

	if (moveCount == 0)
	{
		// Double and single move forward:
		if (!gameBoard.getSquares((ChessCol)i, row + direction)->getOccupied() && !gameBoard.getSquares((ChessCol)i, row + (2 * direction))->getOccupied())
		{
			gameBoard.getSquares((ChessCol)i, row + direction)->setState(ACTIVE);
			gameBoard.getSquares((ChessCol)i, row + (2 * direction))->setState(ACTIVE);
		}
	}
	else
	{
		// single move forward
		if (!gameBoard.getSquares((ChessCol)i, row + direction)->getOccupied())
		{
			gameBoard.getSquares((ChessCol)i, row + direction)->setState(ACTIVE);
		}
	}

	// Attacking Diagonal
	if (row + direction >= 0 && row + direction < 8)
	{
		if (i + 1 < 8 && gameBoard.getSquares((ChessCol)(i + 1), row + direction)->getOccupied() && gameBoard.getSquares((ChessCol)(i + 1), row + direction)->getOccupiedColor() != color && gameBoard.getSquares((ChessCol)(i + 1), row + direction)->getOccupiedColor() != "None")
		{
			gameBoard.getSquares((ChessCol)(i + 1), row + direction)->setState(ACTIVE);
		}

		if (i - 1 >= 0 && gameBoard.getSquares((ChessCol)(i - 1), row + direction)->getOccupied() && gameBoard.getSquares((ChessCol)(i - 1), row + direction)->getOccupiedColor() != color && gameBoard.getSquares((ChessCol)(i - 1), row + direction)->getOccupiedColor() != "None")
		{
			gameBoard.getSquares((ChessCol)(i - 1), row + direction)->setState(ACTIVE);
		}
	}
}