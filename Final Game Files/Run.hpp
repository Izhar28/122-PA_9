// This Header File contains every other Header File so that it can run the game of chess.
// The class contains the functions that will allow the player to interact with the game and play
#pragma once
#include <stack>
#include "Board.hpp"
#include "Welcome.hpp"
#include "BackDrop.hpp"
#include "RandomizeButton.hpp"
#include "StandardButton.hpp"
#include "UndoButton.hpp"
#include "Move.hpp"
#include "BackButton.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"

class Run
{
public:
	Run();
	~Run();
	void undoLastMove(Board& board);
	void printMove(Move& m, Piece* p);
	void move(Board* gameBoard, sf::Vector2f mouse, Piece* piece, int* state);

	void initializePieces(Board& gameBoard);
	void DrawPieces(sf::RenderWindow* window);
	void clickedMain(sf::Vector2f mouse, int* state);
	void clickedGame(Piece* p, sf::Vector2f& mouse, int* state, Board& gameBoard);

	static void loadTextures();

	std::vector<Piece*> pieces;
	Mode mode;
	Clicked clicked;
	Piece* selectedPiece;
	std::stack<Move> moves;
	Welcome* WelcomeBackDrop;
	BackDrop* Back;
	RandomizeButton* Randomized;
	StandardButton* Standard;
	UndoButton* Undo;
	BackButton* backButton;
	std::string turn;

	// pieces:
	Knight blackKnight1, blackKnight2, whiteKnight1, whiteKnight2;
	Rook blackRook1, blackRook2, whiteRook1, whiteRook2;
	Queen blackQueen, whiteQueen;
	King blackKing, whiteKing;
	Bishop blackBishop1, blackBishop2, whiteBishop1, whiteBishop2;

	Pawn wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8; // white Pawns
	Pawn bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8; // black Pawns

	// textures
	static sf::Texture welcome, backDrop, random, standard, Backtext, undoButton, whiteWins, blackWins, underConstruction;


};
