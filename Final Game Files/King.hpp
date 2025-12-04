// This Header File contains the class of the King piece in chess.
// This class assignes the color of the piece and determines the movement pattern of the piece
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
