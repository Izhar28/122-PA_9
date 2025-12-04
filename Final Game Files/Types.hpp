// This Header File contains multiple classes that all determine different asepcts of the game.
// For instance the class Chesscol sets the names of all the colums on the board and the struct state
// determines if a square is is active or not, or occupied or not. This File also uses another struct that determines
// If the player had clicked on a chess piece or not as well as the back button on the menu.
#pragma once
#include <iostream>

enum class ChessCol 
{ 
	A, B, C, D, E, F, G, H 
};

typedef enum state
{
	IDLE = 0, ACTIVE = 1
} State;

typedef enum mode
{
	STANDARD = 0, RANDOM = 1
} Mode;

typedef enum clicked // represents which object is clicked on
{
	NONE = 0, UNDO = 1, BACKBUTTON = 2, ROOK = 3, KNIGHT = 4, BISHOP = 5, KING = 6, QUEEN = 7, PAWN = 8
} Clicked;

typedef struct whiteMove
{
	ChessCol column, prevCol;
	Clicked piece;
	int row, prevRow;
	bool takes;
} WhiteMove;

typedef struct blackMove
{
	ChessCol column, prevCol;
	Clicked piece;
	int row, prevRow;
	bool takes;

} BlackMove;
