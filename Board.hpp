#pragma once
#include "Square.hpp"

typedef enum mode
{
	STANDARD = 0, RANDOM = 1
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