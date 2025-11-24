#pragma once
#include "Coord.hpp"

typedef enum mode
{
	Standard = 0, Random = 1
} Mode;

class Board
{
public:
	Board();
	~Board();

private:
	Coord board[8][8];
	sf::RectangleShape shape;
	void initializeBoard(Mode m);
};