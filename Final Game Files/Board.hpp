// This Header File contains the class for the chessboard itself.
// This class contains the functions that allows the board to be printed and contains the functions that 
// gets each of the individual squares from the squares class from the Square hpp File. 
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
