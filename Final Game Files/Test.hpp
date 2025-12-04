// This Header File contains the different tests that were applied to this project.
#pragma once
#include "Run.hpp"

/*
* Chat-GPT created these test functions and the prompt that it was given was "Can you take 5 functions, from the file I am going to give you and create test functions for them that will be included in their own file and can you comment them please."; the "Run.cpp" file was pasted into the chat box for the AI model to create the test functions from
*/

// Test function for undoLastMove
void testUndoLastMove()
{
    Board board;
    Run game;

    // Initialize pieces
    game.initializePieces(board);

    // Make a dummy move with a white pawn
    Pawn* pawn = dynamic_cast<Pawn*>(&game.wPawn1);
    game.clicked = PAWN;
    sf::Vector2f target(100, 100); // Mock mouse position; adjust to your board logic
    int state = 0;
    game.move(&board, target, pawn, &state);

    // Undo the last move
    game.undoLastMove(board);

    // Pawn should be back at its initial position
    assert(pawn->getRow() == 1 && pawn->getColumn() == ChessCol::A);
    std::cout << "testUndoLastMove passed!" << std::endl;
}

// Test function for move
void testMove()
{
    Board board;
    Run game;
    game.initializePieces(board);

    Pawn* pawn = dynamic_cast<Pawn*>(&game.wPawn2);
    game.clicked = PAWN;
    sf::Vector2f target(100, 100); // Mock mouse position; adjust to your board logic
    int state = 0;

    game.move(&board, target, pawn, &state);

    // Check that pawn's row has changed
    assert(pawn->getRow() != 1);
    std::cout << "testMove passed!" << std::endl;
}

// Test function for initializePieces
void testInitializePieces()
{
    Board board;
    Run game;
    game.initializePieces(board);

    // Check some pieces are at expected initial positions
    assert(game.wPawn1.getRow() == 1 && game.wPawn1.getColumn() == ChessCol::A);
    assert(game.bPawn8.getRow() == 6 && game.bPawn8.getColumn() == ChessCol::H);
    assert(game.whiteKing.getRow() == 0 && game.whiteKing.getColumn() == ChessCol::D);

    std::cout << "testInitializePieces passed!" << std::endl;
}

// Test function for clickedMain
void testClickedMain()
{
    Run game;
    int state = 0;
    sf::Vector2f mousePosition(50, 50); // Adjust to be inside the Standard button

    game.clickedMain(mousePosition, &state);

    // Check that state changed to 1
    assert(state == 1);
    std::cout << "testClickedMain passed!" << std::endl;
}

// Test function for clickedGame
void testClickedGame()
{
    Board board;
    Run game;
    game.initializePieces(board);

    Pawn* pawn = dynamic_cast<Pawn*>(&game.wPawn3);
    sf::Vector2f mousePos(0, 0); // Just a placeholder; game logic uses board squares

    int state = 0;
    game.clickedGame(pawn, mousePos, &state, board);

    // The clicked piece should be the selected piece
    assert(game.selectedPiece == pawn);
    std::cout << "testClickedGame passed!" << std::endl;

}
