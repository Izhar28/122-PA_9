#pragma once
#include "Square.hpp"

typedef enum mode
{
	Standard = 0, Random = 1
} Mode;

class Board
{
public:
	Board();
	~Board();
	void Draw(sf::RenderWindow& window);
private:
	Square squares[8][8];
	void initializeBoard();
};