#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"
#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn();
	Pawn(std::string newColor);
	~Pawn();

	void movementSquares(Board& gameBoard) override;
	void addMove();
	void resetMove();
private:
	int moveCount;
};