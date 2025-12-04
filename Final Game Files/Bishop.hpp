#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(std::string newColor);
	~Bishop();

	void movementSquares(Board& gameBoard) override;
};