#pragma once
#include <vector>
#include "Square.hpp"


class Board
{
public:
	Board();
	~Board();
	void Draw(sf::RenderWindow& window);
	Square* getSquares(ChessCol column, int row);

	void deactivateSquares();
private:
	std::vector<std::vector<Square>> squares;
	void initializeBoard();
};