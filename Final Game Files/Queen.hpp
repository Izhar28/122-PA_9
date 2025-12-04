#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Queen : public Piece
{
public:
	Queen();
	Queen(std::string newColor);
	~Queen();

	void movementSquares(Board& gameBoard) override;
};