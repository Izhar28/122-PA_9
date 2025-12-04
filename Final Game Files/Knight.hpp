#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Knight : public Piece
{
public:
	Knight();
	Knight(std::string newColor);
	~Knight();

	void movementSquares(Board& gameBoard) override;
};