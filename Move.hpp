#pragma once
#include <SFML/Graphics.hpp>

typedef struct white
{
	char piece, column;
	int row;
} White;

typedef struct black
{
	char piece, column;
	int row;
} Black;

class Move
{
public:
	Move()
	{
		whiteMove.piece = whiteMove.column = blackMove.piece = blackMove.column = '\0';
		whiteMove.row = blackMove.row = -1;
	}
	~Move() {}
	White getWhiteMove() const { return whiteMove; }
	Black getBlackMove() const { return blackMove; }

	void setWhiteMove(White const newMove) { whiteMove = newMove; }
	void setBlackMove(Black const newMove) { blackMove = newMove; }

private:
	white whiteMove;
	black blackMove;
};