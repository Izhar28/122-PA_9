#include "Run.hpp"

int main(void)
{
    Piece::loadTextures();
    Run::loadTextures();
    Square::loadTextures();
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 1000, 1000 }), "Checkers-Adjacent");
    Run run;
    bool initialized = false;

    Board* gameBoard = new Board;
    sf::Vector2f mouse;
    int state = 0;

    srand(NULL);

    while (window->isOpen()) // While game is running
    {

        if (state == 0) // Gameplay is not active
        {
            run.Back->Normal(run.backDrop);
            window->clear(sf::Color::Black);
            window->draw(*run.WelcomeBackDrop);
            window->draw(*run.Randomized);
            window->draw(*run.Standard);
        }
        else if (state == 1 && run.mode == STANDARD)// Gameplay is active
        {
            if (!initialized)
            {
                run.initializePieces(*gameBoard);
                initialized = true;
            }
            
            window->clear(sf::Color::Black);
            window->draw(*run.Back);
            gameBoard->Draw(*window);
            window->draw(*run.Undo);
            window->draw(*run.backButton);
            run.DrawPieces(window);
        }
        else if (state == 1 && run.mode == RANDOM) // Random -- under Construction
        {
            window->clear(sf::Color::Black);
            window->draw(*run.Back);
            window->draw(*run.backButton);
        }
        else if (state > 1) // Black Wins
        {
            run.Back->Wins(state, run.whiteWins, run.blackWins);
            window->clear(sf::Color::Black);
            window->draw(*run.Back);
            window->draw(*run.backButton);
        }

        window->display();

        mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window)); // updates position of mouse

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }

            if (event->is<sf::Event::MouseButtonPressed>()) // if mouse Button pressed
            {
                if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) // If mouse button is clicked
                {
                    if (state == 0)
                    {
                        run.clickedMain(mouse, &state);
                    }
                    else // Gameplay is active
                    {
                        if (!initialized) // if pieces have not been initialized, then initialize them
                        {
                            run.initializePieces(*gameBoard);
                            initialized = true;
                        }
                        if (run.Undo->getGlobalBounds().contains(mouse)) // undo button
                        {
                            run.clicked = UNDO;
                            gameBoard->deactivateSquares();
                            run.undoLastMove(*gameBoard);
                        }
                        else if (run.backButton->getGlobalBounds().contains(mouse)) // back to main menu button
                        {
                            run.clicked = BACKBUTTON;
                            state = 0;
                            gameBoard->deactivateSquares();
                            initialized = false;
                        }
                        else
                        {
                            // checks to see which turn it is and if the correct colors turn is being activated, the move will be followed through
                            for (int i = 0; i < run.pieces.size(); ++i)
                            {
                                Piece* p = run.pieces[i];
                                if (p != nullptr && p->getGlobalBounds().contains(mouse) && p->getColor() == run.turn)
                                {
                                    run.clickedGame(p, mouse, &state, *gameBoard);
                                }
                            }
                            
                            if (run.selectedPiece) // if a piece is currently selected
                            {
                                for (int i = 0; i < 8; ++i) // checks for active squares -- columns
                                {
                                    for (int j = 0; j < 8; ++j)  // checks for active squares -- rows
                                    {
                                        if (gameBoard->getSquares((ChessCol)i, j)->getState() == ACTIVE && gameBoard->getSquares((ChessCol)i, j)->getGlobalBounds().contains(mouse))
                                        {
                                            run.move(gameBoard, mouse, run.selectedPiece, &state); // move piece
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Deallocations:
    delete window;
    return 0;
}

