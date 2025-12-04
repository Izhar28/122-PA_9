#pragma once
#include <SFML/Graphics.hpp>
#include "Types.hpp"
#include "Board.hpp"

class Piece : public sf::RectangleShape // Abstract Class
{
public:
	Piece();
	virtual ~Piece();

	ChessCol getColumn() const;
	int getRow() const;
	std::string getColor() const;


	void setColor(std::string const newColor);
	void moveTo(ChessCol col, int row, Board& board);
	virtual void movementSquares(Board& gameBoard) = 0; // Pure Virtual
	static void loadTextures();

protected:
	int row;
	ChessCol column;
	std::string color;
	void SetPosition(ChessCol newColumn, int newRow, Board& gameBoard);

	static sf::Texture BluePawn, TanPawn, BlueRook, TanRook, BlueKnight, TanKnight, BlueBishop, TanBishop, BlueQueen, TanQueen, BlueKing, TanKing;
};