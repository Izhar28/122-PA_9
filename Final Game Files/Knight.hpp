// This Header File contains the class of the Knight piece in chess.
// This class assignes the color of the piece and determines the movement pattern of the piece
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
