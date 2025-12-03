#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <cstdlib>
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

void undoLastMove(std::stack<Move>& history, Board& board)
{
    if (history.empty())
    {
        std::cout << "---No moves left to undo---" << std::endl;
        return;
    }

    Move lastMove = history.top();
    history.pop();

    std::cout << "--- UNDOING MOVE ---" << std::endl;
    std::cout << "---Move popped from stack. Move count is now: " << history.size() << "---" << std::endl;
}

void printMove(Move& m)
{
    char col = (m.getWhiteMove().column == A) ? 'A' : (m.getWhiteMove().column == B) ? 'B' : (m.getWhiteMove().column == C) ? 'C' : (m.getWhiteMove().column == D) ? 'D' : (m.getWhiteMove().column == E) ? 'E' : (m.getWhiteMove().column == F) ? 'F' : (m.getWhiteMove().column == G) ? 'G' : 'H';

    switch (m.getWhiteMove().piece)
    {
    case ROOK:
        if (!m.getWhiteMove().takes) std::cout << "R" << col << m.getWhiteMove().row;
        else std::cout << "Rx" << col << m.getWhiteMove().row;
        break;
    case KNIGHT: return;
    case BISHOP: return;
    case KING: return;
    case QUEEN: return;
    case PAWN: return;
    }

    col = (m.getBlackMove().column == A) ? 'A' : (m.getBlackMove().column == B) ? 'B' : (m.getBlackMove().column == C) ? 'C' : (m.getBlackMove().column == D) ? 'D' : (m.getBlackMove().column == E) ? 'E' : (m.getBlackMove().column == F) ? 'F' : (m.getBlackMove().column == G) ? 'G' : 'H';

    switch (m.getBlackMove().piece)
    {
    case ROOK:
        if (!m.getBlackMove().takes) std::cout << "\tN" << col << m.getBlackMove().row + 1 << std::endl;
        else std::cout << "\tNx" << col << m.getBlackMove().row + 1 << std::endl;
        break;
    case KNIGHT: return;
    case BISHOP: return;
    case KING: return;
    case QUEEN: return;
    case PAWN: return;
    }
}

void move(Clicked* clicked, Board* gameBoard, sf::Vector2f mouse, Piece* piece, std::stack<Move>& moveHistory)
{
    Column col = A;
    int row = 1;
    bool didMove = false;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (gameBoard->getSquares((Column)i, j)->getGlobalBounds().contains(mouse) &&
                gameBoard->getSquares((Column)i, j)->getState() == ACTIVE)
            {
                col = (Column)i;
                row = j;
                didMove = true;
                goto out;
            }
        }
    }

out:
    if (!didMove) return;

    if (*clicked == PAWN) dynamic_cast<Pawn*>(piece)->addMove(); // If Pawn add move (so not repeating first move)

    piece->moveTo(col, row, *gameBoard);
    gameBoard->deactivateSquares();

    Move m;

    if (piece->getColor() == "White")
    {
        WhiteMove wm;
        wm.column = col;
        wm.row = row;
        wm.piece = *clicked;
        m.setWhiteMove(wm);
    }
    else
    {
        BlackMove bm;
        bm.column = col;
        bm.row = row;
        bm.piece = *clicked;
        m.setBlackMove(bm);
    }

    moveHistory.push(m);
    printMove(m);

    *clicked = NONE;
}

int main(void)
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 1000, 1000 }), "Checkers-Adjacent");
    std::stack<Move> moves;

    Welcome* WelcomeBackDrop = new Welcome;
    BackDrop* Back = new BackDrop;
    RandomizeButton* Randomized = new RandomizeButton;
    StandardButton* Standard = new StandardButton;
    UndoButton* Undo = new UndoButton;
    BackButton* backButton = new BackButton;

    Mode mode = STANDARD;
    Board* gameBoard = new Board;
    sf::Vector2f mouse;
    int state = 0;
    Clicked clicked = NONE;
    Piece* selectedPiece = nullptr;
    Rook r1;
    Knight n1;
    Pawn p1;
    n1.moveTo(B, 0, *gameBoard);
    p1.moveTo(A, 1, *gameBoard);

    srand(NULL);

    while (window->isOpen()) // While game is running
    {

        if (!state) // Gameplay is not active
        {
            window->clear(sf::Color::Black);
            window->draw(*WelcomeBackDrop);
            window->draw(*Randomized);
            window->draw(*Standard);
        }
        else // Gameplay is active
        {
            window->clear(sf::Color::Black);
            window->draw(*Back);
            gameBoard->Draw(*window);
            window->draw(*Undo);
            window->draw(*backButton);
            window->draw(r1);
            window->draw(n1);
            window->draw(p1);
        }

        window->display();

        mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window)); // position of mouse

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();

            if (event->is<sf::Event::MouseButtonPressed>()) // Button pressed?
            {
                if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left)
                {
                    if (state == 0)
                    {
                        if (Standard->getGlobalBounds().contains(mouse)) // Activates Standard Mode
                        {
                            mode = STANDARD;
                            state = 1;
                            std::cout << "---Game Mode: Standard---" << std::endl << "White:\tBlack:" << std::endl;
                        }
                        else if (Randomized->getGlobalBounds().contains(mouse)) // Activates Randomized Mode
                        {
                            mode = RANDOM;
                            state = 1;
                            std::cout << "---Game Mode: Random---" << std::endl << "White:\tBlack:" << std::endl;
                        }
                    }
                    else if (state == 1) // Gameplay is active
                    {
                        if (selectedPiece)
                        {
                            gameBoard->deactivateSquares();
                            selectedPiece->movementSquares(*gameBoard);
                            move(&clicked, gameBoard, mouse, selectedPiece, moves);
                        }
                        if (Undo->getGlobalBounds().contains(mouse)) // Undo button
                        {
                            clicked = UNDO;
                            gameBoard->deactivateSquares();
                            undoLastMove(moves, *gameBoard);
                        }
                        else if (backButton->getGlobalBounds().contains(mouse)) // Back to Main Menu Button
                        {
                            state = 0;
                            clicked = BACKBUTTON;
                            gameBoard->deactivateSquares();
                            std::cout << "---Back to Main Menu---" << std::endl;
                        }
                        else if (r1.getGlobalBounds().contains(mouse)) // Click on Rook
                        {
                            clicked = ROOK;
                            gameBoard->deactivateSquares();
                            r1.movementSquares(*gameBoard);
                            selectedPiece = &r1;
                        }
                        else if (n1.getGlobalBounds().contains(mouse)) // Click on Rook
                        {
                            clicked = KNIGHT;
                            gameBoard->deactivateSquares();
                            n1.movementSquares(*gameBoard);
                            selectedPiece = &n1;
                        }
                        else if (p1.getGlobalBounds().contains(mouse)) // Click on Rook
                        {
                            clicked = PAWN;
                            gameBoard->deactivateSquares();
                            p1.movementSquares(*gameBoard);
                            selectedPiece = &p1;
                        }
                    }
                }
            }
        }
    }

    // Deallocations:
    delete window;
    delete WelcomeBackDrop;
    delete Back;
    delete Randomized;
    delete Standard;
    delete Undo;
    delete backButton;
    return 0;
}