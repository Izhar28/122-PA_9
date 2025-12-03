#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn() : Piece()
	{
		color = "Blank";
		moveCount = 0;
		// temporary ---------------
		piece = new sf::Texture;
		if (piece->loadFromFile("TanPawn.png") == false) return;
		setTexture(piece);
	}
	Pawn(Board& gameBoard, std::string newColor) : Piece()
	{
		piece = new sf::Texture;
		moveCount = 0;
		SetPosition(A, 1, gameBoard);
		if (newColor == "Black")
		{
			if (piece->loadFromFile("BluePawn.png") == false) return;
		}
		else if (newColor == "White")
		{
			if (piece->loadFromFile("TanPawn.png") == false) return;
		}
		setTexture(piece);
	}
	~Pawn() { delete piece; }

	void movementSquares(Board& gameBoard) override;
	void addMove() { ++moveCount; }
private:
	int moveCount;
};

void Pawn::movementSquares(Board& gameBoard)
{
	int i = (int)column;

	if (moveCount == 0)
	{
		if (!gameBoard.getSquares((Column)i, row + 2)->getOccupied() && !gameBoard.getSquares((Column)i, row + 1)->getOccupied())
		{
			gameBoard.getSquares((Column)i, row + 2)->setState(ACTIVE);
			gameBoard.getSquares((Column)i, row + 1)->setState(ACTIVE);
		}
	}
	else
	{
		if (!gameBoard.getSquares((Column)i, row + 1)->getOccupied())
		{
			gameBoard.getSquares((Column)i, row + 1)->setState(ACTIVE);
		}
	}

	if (i + 1 < 8 && gameBoard.getSquares((Column)(i + 1), row + 1)->getOccupied() && gameBoard.getSquares((Column)(i + 1), row + 1)->getOccupiedColor() != color && gameBoard.getSquares((Column)(i + 1), row + 1)->getOccupiedColor() != "None")
	{
		gameBoard.getSquares((Column)(i + 1), row + 1)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && gameBoard.getSquares((Column)(i - 1), row + 1)->getOccupied() && gameBoard.getSquares((Column)(i - 1), row + 1)->getOccupiedColor() != color && gameBoard.getSquares((Column)(i - 1), row + 1)->getOccupiedColor() != "None")
	{
		gameBoard.getSquares((Column)(i - 1), row + 1)->setState(ACTIVE);
	}
}





