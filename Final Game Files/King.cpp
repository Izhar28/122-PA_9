// This cpp File contains all the code that relates to the King piece in the game of chess. 
// This File contains the code to determine the color of the piece and the movement pattern the King has in a regular game.
#include "King.hpp"

King::King() : Piece()
{
	color = "Blank";
}

King::King(std::string newColor) : Piece()
{
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BlueKing);
	}
	else if (newColor == "White")
	{
		setTexture(&TanKing);
	}
}

King::~King()
{  
}

void King::movementSquares(Board& gameBoard)
{
	int i = (int)column;

	if (i + 1 < 8 && row + 1 < 8 && (!gameBoard.getSquares((ChessCol)(i + 1), row + 1)->getOccupied() || gameBoard.getSquares((ChessCol)(i + 1), row + 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i + 1), row + 1)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && row + 1 < 8 && (!gameBoard.getSquares((ChessCol)(i - 1), row + 1)->getOccupied() || gameBoard.getSquares((ChessCol)(i - 1), row + 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i - 1), row + 1)->setState(ACTIVE);
	}

	if (i + 1 < 8 && row - 1 >= 0 && (!gameBoard.getSquares((ChessCol)(i + 1), row - 1)->getOccupied() || gameBoard.getSquares((ChessCol)(i + 1), row - 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i + 1), row - 1)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && row - 1 >= 0 && (!gameBoard.getSquares((ChessCol)(i - 1), row - 1)->getOccupied() || gameBoard.getSquares((ChessCol)(i - 1), row - 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i - 1), row - 1)->setState(ACTIVE);
	}

	if (i + 1 < 8 && (!gameBoard.getSquares((ChessCol)(i + 1), row)->getOccupied() || gameBoard.getSquares((ChessCol)(i + 1), row)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i + 1), row)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && (!gameBoard.getSquares((ChessCol)(i - 1), row)->getOccupied() || gameBoard.getSquares((ChessCol)(i - 1), row)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)(i - 1), row)->setState(ACTIVE);
	}

	if (row + 1 < 8 && (!gameBoard.getSquares((ChessCol)i, row + 1)->getOccupied() || gameBoard.getSquares((ChessCol)i, row + 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)i, row + 1)->setState(ACTIVE);
	}

	if (row - 1 >= 0 && (!gameBoard.getSquares((ChessCol)i, row - 1)->getOccupied() || gameBoard.getSquares((ChessCol)i, row - 1)->getOccupiedColor() != color))
	{
		gameBoard.getSquares((ChessCol)i, row - 1)->setState(ACTIVE);
	}
}

