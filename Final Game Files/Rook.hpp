#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Rook : public Piece
{
public:
	Rook();
	Rook(std::string newColor);
	~Rook();

	void movementSquares(Board& gameBoard) override;
};