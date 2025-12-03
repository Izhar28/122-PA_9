#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Board.hpp"


class Piece : public sf::RectangleShape // Abstract Class
{
public:
	Piece() : sf::RectangleShape(sf::Vector2f(125, 125))
	{
		setPosition(sf::Vector2f(90, 80));
		row = 0;
		column = A;
		piece = nullptr;
	}
	virtual ~Piece() { delete piece; }

	Column getColumn() const { return column; }
	int getRow() const { return row; }
	std::string getColor() const { return color; }


	void setColor(std::string const newColor) { color = newColor; }

	virtual void moveTo(Column col, int row, Board& board)
	{
		SetPosition(col, row, board);
	}
	virtual void movementSquares(Board& gameBoard) = 0; // Pure Virtual

protected:
	sf::Texture* piece;
	int row;
	Column column;
	std::string color;
	void SetPosition(Column newColumn, int newRow, Board& gameBoard);
};


/*
Columns:
	A -> x = 90;
	B -> x = 190;
	C -> x = 290;
	D -> x = 390;
	E -> x = 490;
	F -> x = 590;
	G -> x = 690;
	H -> x = 790;
Rows:
	1 -> y = 80;
	2 -> y = 180;
	3 -> y = 280;
	4 -> y = 380;
	5 -> y = 480;
	6 -> y = 580;
	7 -> y = 680;
	8 -> y = 780;
*/

inline void Piece::SetPosition(Column newColumn, int newRow, Board& gameBoard)
{
	float x = 0.0, y = 0.0;
	gameBoard.getSquares(column, row)->setOccupied(false);
	gameBoard.getSquares(column, row)->setOccupiedColor("None");// square is no longer occupied
	column = newColumn;
	row = newRow;
	switch (newColumn) // sets positioning for x
	{
	case A: x = 90; break;
	case B: x = 190; break;
	case C: x = 290; break;
	case D: x = 390; break;
	case E: x = 490; break;
	case F: x = 590; break;
	case G: x = 690; break;
	case H: x = 790; break;
	}

	switch (newRow) // sets positioning for y
	{
	case 0: y = 80; break;
	case 1: y = 180; break;
	case 2: y = 280; break;
	case 3: y = 380; break;
	case 4: y = 480; break;
	case 5: y = 580; break;
	case 6: y = 680; break;
	case 7: y = 780; break;
	}

	setPosition(sf::Vector2f(x, y));
	gameBoard.getSquares(column, row)->setOccupied(true); // square is occupied
	gameBoard.getSquares(column, row)->setOccupiedColor(color);
}
