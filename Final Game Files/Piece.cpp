#include "Piece.hpp"

sf::Texture Piece::BluePawn, Piece::TanPawn, Piece::BlueRook, Piece::TanRook, Piece::BlueKnight, Piece::TanKnight, Piece::BlueBishop, Piece::TanBishop, Piece::BlueQueen, Piece::TanQueen, Piece::BlueKing, Piece::TanKing;

Piece::Piece() : sf::RectangleShape(sf::Vector2f(125, 125))
{
	setPosition(sf::Vector2f(90, 80));
	row = 0;
	column = ChessCol::A;
}

Piece::~Piece()
{ 
}

ChessCol Piece::getColumn() const
{ 
	return column; 
}

int Piece::getRow() const 
{ 
	return row; 
}

std::string Piece::getColor() const 
{ 
	return color;
}


void Piece::setColor(std::string const newColor) 
{ 
	color = newColor; 
}

void Piece::moveTo(ChessCol col, int row, Board& board)
{
	SetPosition(col, row, board);
}

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

inline void Piece::SetPosition(ChessCol newColumn, int newRow, Board& gameBoard)
{
	float x = 0.0, y = 0.0;
	gameBoard.getSquares(column, row)->setOccupied(false);
	gameBoard.getSquares(column, row)->setOccupiedColor("None");// square is no longer occupied
	gameBoard.getSquares(column, row)->setOccupyingPiece(nullptr);
	column = newColumn;
	row = newRow;
	switch (newColumn) // sets positioning for x
	{
	case ChessCol::A: x = 90; break;
	case ChessCol::B: x = 190; break;
	case ChessCol::C: x = 290; break;
	case ChessCol::D: x = 390; break;
	case ChessCol::E: x = 490; break;
	case ChessCol::F: x = 590; break;
	case ChessCol::G: x = 690; break;
	case ChessCol::H: x = 790; break;
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
	gameBoard.getSquares(column, row)->setOccupyingPiece(this);
}

void Piece::loadTextures()
{
	TanPawn.loadFromFile("TanPawn.png");
	BluePawn.loadFromFile("BluePawn.png");
	BlueRook.loadFromFile("BlueRook.png");
	TanRook.loadFromFile("TanRook.png");
	BlueKnight.loadFromFile("BlueKnight.png");
	TanKnight.loadFromFile("TanKnight.png");
	BlueBishop.loadFromFile("BlueBishop.png");
	TanBishop.loadFromFile("TanBishop.png");
	BlueQueen.loadFromFile("BlueQueen.png");
	TanQueen.loadFromFile("TanQueen.png");
	BlueKing.loadFromFile("BlueKing.png");
	TanKing.loadFromFile("TanKing.png");
}