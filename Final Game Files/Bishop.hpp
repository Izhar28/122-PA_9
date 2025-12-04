// This Header File contains the class of the Bishop piece in chess.
// This class assigns the color of the piece and determines the movement pattern of the piece

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

