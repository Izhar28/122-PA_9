#include "Bishop.hpp"


Bishop::Bishop() : Piece()
{
	color = "Blank";
}

Bishop::Bishop(std::string newColor) : Piece()
{
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BlueBishop);
	}
	else if (newColor == "White")
	{
		setTexture(&TanBishop);
	}
}

Bishop::~Bishop()
{ 
}

void Bishop::movementSquares(Board& gameBoard)
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
		--c;
		++r;
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
		++c;
		--r;
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
		--c;
		--r;
	}

	if (c >= 0 && r >= 0 && gameBoard.getSquares((ChessCol)c, r)->getOccupied() && gameBoard.getSquares((ChessCol)c, r)->getOccupiedColor() != color)
	{
		gameBoard.getSquares((ChessCol)c, r)->setState(ACTIVE);
	}
}
