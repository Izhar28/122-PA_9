#pragma once
#include <SFML/Graphics.hpp>

typedef enum clicked
{
	NONE = 0, UNDO = 1, BACKBUTTON = 2, ROOK = 3, KNIGHT = 4, BISHOP = 5, KING = 6, QUEEN = 7, PAWN = 8
} Clicked;

typedef struct whiteMove
{
	char column;
	Clicked piece;
	int row;
	bool takes;
} WhiteMove;

typedef struct blackMove
{
	char column;
	Clicked piece;
	int row;
	bool takes;
} BlackMove;

class Move
{
public:
	Move()
	{
		whiteMove.column = blackMove.column = '\0';
		whiteMove.piece = blackMove.piece = NONE;
		whiteMove.row = blackMove.row = 0;
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