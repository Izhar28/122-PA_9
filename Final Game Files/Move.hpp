// This Header File contains the class that contains the functions that set the movements of each piece.
// This class also gets the moves from the user for each piece.
#pragma once
#include <SFML/Graphics.hpp>
#include "Types.hpp"

class Move
{
public:
	Move()
	{
		whiteMove.column = blackMove.column = whiteMove.prevCol = blackMove.prevCol = ChessCol::A;
		whiteMove.piece = blackMove.piece = NONE;
		whiteMove.row = blackMove.row = whiteMove.prevRow = blackMove.prevRow = 0;
	}
	~Move() {}
	WhiteMove getWhiteMove() { return whiteMove; }
	BlackMove getBlackMove() { return blackMove; }

	void setWhiteMove(WhiteMove const newMove) { whiteMove = newMove; }
	void setBlackMove(BlackMove const newMove) { blackMove = newMove; }

private:
	WhiteMove whiteMove;
	BlackMove blackMove;

};
