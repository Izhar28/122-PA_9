#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Knight : public Piece
{
public:
	Knight() : Piece()
	{
		color = "Blank";

		// temporary ---------------
		piece = new sf::Texture;
		if (piece->loadFromFile("TanKnight.png") == false) return;
		setTexture(piece);
	}
	Knight(Board& gameBoard, std::string newColor) : Piece()
	{
		piece = new sf::Texture;
		SetPosition(A, 2, gameBoard);
		if (newColor == "Black")
		{
			if (piece->loadFromFile("BlueKnight.png") == false) return;
		}
		else if (newColor == "White")
		{
			if (piece->loadFromFile("TanKnight.png") == false) return;
		}
		setTexture(piece);
	}
	~Knight() { delete piece; }

	void movementSquares(Board& gameBoard) override;
};

void Knight::movementSquares(Board& gameBoard)
{
	int i = (int)column;

	if (i + 1 < 8 && row + 2 < 8 && !gameBoard.getSquares((Column)(i + 1), row + 2)->getOccupied())
	{
		gameBoard.getSquares((Column)(i + 1), row + 2)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && row + 2 < 8 && !gameBoard.getSquares((Column)(i - 1), row + 2)->getOccupied())
	{
		gameBoard.getSquares((Column)(i - 1), row + 2)->setState(ACTIVE);
	}

	if (i + 1 < 8 && row - 2 >= 0 && !gameBoard.getSquares((Column)(i + 1), row - 2)->getOccupied())
	{
		gameBoard.getSquares((Column)(i + 1), row - 2)->setState(ACTIVE);
	}

	if (i - 1 >= 0 && row - 2 >= 0 && !gameBoard.getSquares((Column)(i - 1), row - 2)->getOccupied())
	{
		gameBoard.getSquares((Column)(i - 1), row - 2)->setState(ACTIVE);
	}

	if (i + 2 < 8 && row + 1 < 8 && !gameBoard.getSquares((Column)(i + 2), row + 1)->getOccupied())
	{
		gameBoard.getSquares((Column)(i + 2), row + 1)->setState(ACTIVE);
	}

	if (i - 2 >= 0 && row + 1 < 8 && !gameBoard.getSquares((Column)(i - 2), row + 1)->getOccupied())
	{
		gameBoard.getSquares((Column)(i - 2), row + 1)->setState(ACTIVE);
	}

	if (i + 2 < 8 && row - 1 >= 0 && !gameBoard.getSquares((Column)(i + 2), row - 1)->getOccupied())
	{
		gameBoard.getSquares((Column)(i + 2), row - 1)->setState(ACTIVE);
	}

	if (i - 2 >= 0 && row - 1 >= 0 && !gameBoard.getSquares((Column)(i - 2), row - 1)->getOccupied())
	{
		gameBoard.getSquares((Column)(i - 2), row - 1)->setState(ACTIVE);
	}
}
