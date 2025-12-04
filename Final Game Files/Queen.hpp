// This Header File contains the class of the Queen piece in chess.
// This class assignes the color of the piece and determines the movement pattern of the piece
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
