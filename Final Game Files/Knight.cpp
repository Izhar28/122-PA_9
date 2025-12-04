// This cpp File contains all the code that relates to the Knight piece in the game of chess. 
// This File contains the code to determine the color of the piece and the movement pattern the Knight has in a regular game.
#include "Knight.hpp"

Knight::Knight() : Piece()
{
	color = "Blank";
}

Knight::Knight(std::string newColor) : Piece()
{
	color = newColor;
	if (newColor == "Black")
	{
		setTexture(&BlueKnight);
	}
	else if (newColor == "White")
	{
		setTexture(&TanKnight);
	}
}

Knight::~Knight() 
{ 
}

void Knight::movementSquares(Board& gameBoard)
{
	int i = (int)column;

	// column + 1, Row + 2
	if ((i + 1) < 8 && (row + 2) < 8 && (!gameBoard.getSquares((ChessCol)(i + 1), row + 2)->getOccupied() || (gameBoard.getSquares((ChessCol)(i + 1), row + 2)->getOccupied() && gameBoard.getSquares((ChessCol)(i + 1), row + 2)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i + 1), row + 2)->setState(ACTIVE);
	}

	// column - 1, Row + 2
	if ((i - 1) >= 0 && (row + 2) < 8 && (!gameBoard.getSquares((ChessCol)(i - 1), row + 2)->getOccupied() || (gameBoard.getSquares((ChessCol)(i - 1), row + 2)->getOccupied() && gameBoard.getSquares((ChessCol)(i - 1), row + 2)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i - 1), row + 2)->setState(ACTIVE);
	}

	// column + 1, Row - 2
	if ((i + 1) < 8 && (row - 2) >= 0 && (!gameBoard.getSquares((ChessCol)(i + 1), row - 2)->getOccupied() || (gameBoard.getSquares((ChessCol)(i + 1), row - 2)->getOccupied() && gameBoard.getSquares((ChessCol)(i + 1), row - 2)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i + 1), row - 2)->setState(ACTIVE);
	}

	// column - 1, Row - 2
	if ((i - 1) >= 0 && (row - 2) >= 0 && (!gameBoard.getSquares((ChessCol)(i - 1), row - 2)->getOccupied() || (gameBoard.getSquares((ChessCol)(i - 1), row - 2)->getOccupied() && gameBoard.getSquares((ChessCol)(i - 1), row - 2)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i - 1), row - 2)->setState(ACTIVE);
	}

	// column + 2, Row + 1
	if ((i + 2) < 8 && (row + 1) < 8 && (!gameBoard.getSquares((ChessCol)(i + 2), row + 1)->getOccupied() || (gameBoard.getSquares((ChessCol)(i + 2), row + 1)->getOccupied() && gameBoard.getSquares((ChessCol)(i + 2), row + 1)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i + 2), row + 1)->setState(ACTIVE);
	}

	// column - 2, Row + 1
	if ((i - 2) >= 0 && (row + 1) < 8 && (!gameBoard.getSquares((ChessCol)(i - 2), row + 1)->getOccupied() || (gameBoard.getSquares((ChessCol)(i - 2), row + 1)->getOccupied() && gameBoard.getSquares((ChessCol)(i - 2), row + 1)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i - 2), row + 1)->setState(ACTIVE);
	}

	// column + 2, Row - 1
	if ((i + 2) < 8 && (row - 1) >= 0 && (!gameBoard.getSquares((ChessCol)(i + 2), row - 1)->getOccupied() || (gameBoard.getSquares((ChessCol)(i + 2), row - 1)->getOccupied() && gameBoard.getSquares((ChessCol)(i + 2), row - 1)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i + 2), row - 1)->setState(ACTIVE);
	}

	// column - 2, Row - 1
	if ((i - 2) >= 0 && (row - 1) >= 0 && (!gameBoard.getSquares((ChessCol)(i - 2), row - 1)->getOccupied() || (gameBoard.getSquares((ChessCol)(i - 2), row - 1)->getOccupied() && gameBoard.getSquares((ChessCol)(i - 2), row - 1)->getOccupiedColor() != color)))
	{
		gameBoard.getSquares((ChessCol)(i - 2), row - 1)->setState(ACTIVE);
	}

}
