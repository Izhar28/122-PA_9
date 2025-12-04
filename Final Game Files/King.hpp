#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class King : public Piece
{
public:
	King();
	King(std::string newColor);
	~King();
	void movementSquares(Board& gameBoard) override;
};