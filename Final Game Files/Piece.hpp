// This Header File contains the class for each individual piece of the chessboard. This class gets the current column 
// and row location and puts down a chess piece on the current square as long as it isn't occupied.
// This class also sets the color of the pieces depending on the side the pieces are on
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
