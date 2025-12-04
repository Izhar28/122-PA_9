// This Header File contains the class of the Rook piece in chess.
// This class assignes the color of the piece and determines the movement pattern of the piece
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
