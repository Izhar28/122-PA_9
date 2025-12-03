#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Rook : public Piece
{
public:
	Rook() : Piece()
	{
		color = "Blank";

		// temporary ---------------
		piece = new sf::Texture;
		if (piece->loadFromFile("TanRook.png") == false) return;
		setTexture(piece);
	}
	Rook(Board& gameBoard, std::string newColor) : Piece()
	{
		piece = new sf::Texture;
		SetPosition(A, 1, gameBoard);
		if (newColor == "Black")
		{
			if (piece->loadFromFile("BlueRook.png") == false) return;
		}
		else if (newColor == "White")
		{
			if (piece->loadFromFile("TanRook.png") == false) return;
		}
		setTexture(piece);
	}
	~Rook() { delete piece; }

	void movementSquares(Board& gameBoard) override;
};

void Rook::movementSquares(Board& gameBoard)
{
	// right
	for (int i = column + 1; i < 8; ++i)
	{
		if (!gameBoard.getSquares((Column)i, row)->getOccupied())
		{
			gameBoard.getSquares((Column)i, row)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares((Column)i, row)->getOccupiedColor() != color)
			{
				gameBoard.getSquares((Column)i, row)->setState(ACTIVE);
			}
			break;
		}
	}

	// left
	for (int i = column - 1; i >= 0; --i)
	{
		if (!gameBoard.getSquares((Column)i, row)->getOccupied())
		{
			gameBoard.getSquares((Column)i, row)->setState(ACTIVE);
		}
		else
		{
			if (gameBoard.getSquares((Column)i, row)->getOccupiedColor() != color)
			{
				gameBoard.getSquares((Column)i, row)->setState(ACTIVE);
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




