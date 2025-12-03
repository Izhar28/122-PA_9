#pragma once
#include <vector>
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
	Square* getSquares(Column column, int row);

	void deactivateSquares();

private:
	std::vector<std::vector<Square>> squares;
	void initializeBoard();
};