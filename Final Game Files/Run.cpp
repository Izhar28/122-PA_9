// This Header File uses every Header File that is located in the Run.hpp file to run the game of chess.
#include "Run.hpp"

sf::Texture Run::welcome, Run::backDrop, Run::random, Run::standard, Run::Backtext, Run::undoButton, Run::whiteWins, Run::blackWins, Run::underConstruction;

Run::Run() : wPawn1("White"), wPawn2("White"), wPawn3("White"), wPawn4("White"), wPawn5("White"), wPawn6("White"), wPawn7("White"), wPawn8("White"), // White Pawn Initialization
bPawn1("Black"), bPawn2("Black"), bPawn3("Black"), bPawn4("Black"), bPawn5("Black"), bPawn6("Black"), bPawn7("Black"), bPawn8("Black"), // Black Pawn Initialization
blackKnight1("Black"), blackKnight2("Black"), // Black Knight Initialization
whiteKnight1("White"), whiteKnight2("White"), // White Knight Initialization
blackRook1("Black"), blackRook2("Black"), // Black Rook Initialization
whiteRook1("White"), whiteRook2("White"), // White Rook Initialization
blackQueen("Black"), // Black Queen Initialization
whiteQueen("White"), // White Queen Initialization
blackKing("Black"), // Black King Initialization
whiteKing("White"), // White King Initialization
blackBishop1("Black"), blackBishop2("Black"), // Black Bishop Initialization
whiteBishop1("White"), whiteBishop2("White") // White Bishop Initialization
{
    mode = RANDOM;
    clicked = NONE;
    selectedPiece = nullptr;
    WelcomeBackDrop = new Welcome(welcome);
    Back = new BackDrop(backDrop);
    Randomized = new RandomizeButton(random);
    Standard = new StandardButton(standard);
    Undo = new UndoButton(undoButton);
    backButton = new BackButton(Backtext);
    turn = "White";

    pieces = { &blackKnight1, &blackKnight2, &whiteKnight1, &whiteKnight2, &blackRook1, &blackRook2, &whiteRook1, &whiteRook2, &blackQueen, &whiteQueen, &blackKing, &whiteKing, &blackBishop1, &blackBishop2, &whiteBishop1, &whiteBishop2, &wPawn1, &wPawn2, &wPawn3, &wPawn4, &wPawn5, &wPawn6, &wPawn7, &wPawn8, &bPawn1, &bPawn2, &bPawn3, &bPawn4, &bPawn5, &bPawn6, &bPawn7, &bPawn8};

}

Run::~Run()
{
    delete WelcomeBackDrop;
    delete Back;
    delete Randomized;
    delete Standard;
    delete Undo;
    delete backButton;
    while (!moves.empty()) // empty Move History Stack
    {
        moves.pop();
    }
}

void Run::undoLastMove(Board& board)
{
    if (moves.empty())
    {
        std::cout << "---No moves left to undo---" << std::endl;
        return;
    }

    Move lastMove = moves.top();
    moves.pop();

    std::cout << "--- UNDOING MOVE ---" << std::endl;
    std::cout << "---Move popped from stack. Move count is now: " << moves.size() << "Moves---" << std::endl;


    // The rest of this undoLastMove function was made by Chat GPT; Prompt: "I need a function that will move the pieces back if the undo button is clicked. I would like to keep what already exists, so please just add on to it. It uses sfml in c++" and "can you take that function and make it so that it resets movecount for pawns if the first move is undone"
    Piece* p = nullptr;
    ChessCol col;
    int row;
    bool takes = false;

    if (turn == "Black" && lastMove.getWhiteMove().piece != NONE)
    {
        WhiteMove wm = lastMove.getWhiteMove();
        col = wm.column;
        row = wm.row;
        takes = wm.takes;

        for (auto piece : pieces)
        {
            if (piece->getColor() == "White" && piece->getColumn() == col && piece->getRow() == row)
            {
                p = piece;
                break;
            }
        }

        if (p)
        {
            p->moveTo(wm.prevCol, wm.prevRow, board);

            if (wm.piece == PAWN && wm.prevRow == 1)
            {
                dynamic_cast<Pawn*>(p)->resetMove();
            }
        }

        if (takes)
        {
            Square* sq = board.getSquares(col, row);
            Piece* captured = sq->getOccupyingPiece();
            if (captured) captured->moveTo(col, row, board);
        }
    }
    else if (turn == "White" && lastMove.getBlackMove().piece != NONE)
    {
        BlackMove bm = lastMove.getBlackMove();
        col = bm.column;
        row = bm.row;
        takes = bm.takes;

        for (auto piece : pieces)
        {
            if (piece->getColor() == "Black" && piece->getColumn() == col && piece->getRow() == row)
            {
                p = piece;
                break;
            }
        }

        if (p)
        {
            p->moveTo(bm.prevCol, bm.prevRow, board);

            if (bm.piece == PAWN && bm.prevRow == 6)
            {
                dynamic_cast<Pawn*>(p)->resetMove();
            }
        }

        if (takes)
        {
            Square* sq = board.getSquares(col, row);
            Piece* captured = sq->getOccupyingPiece();
            if (captured) captured->moveTo(col, row, board);
        }
    }

    turn = (turn == "White") ? "Black" : "White";
}

void Run::printMove(Move& m, Piece* p)
{
    char col;

    if (p->getColor() == "White")
    {
        col = (m.getWhiteMove().column == ChessCol::A) ? 'A' : (m.getWhiteMove().column == ChessCol::B) ? 'B' : (m.getWhiteMove().column == ChessCol::C) ? 'C' :
            (m.getWhiteMove().column == ChessCol::D) ? 'D' : (m.getWhiteMove().column == ChessCol::E) ? 'E' : (m.getWhiteMove().column == ChessCol::F) ? 'F' :
            (m.getWhiteMove().column == ChessCol::G) ? 'G' : 'H';

        switch (m.getWhiteMove().piece)
        {
        case ROOK:
            if (!m.getWhiteMove().takes)
            {
                std::cout << "R" << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "Rx" << col << m.getWhiteMove().row + 1;
            }
            break;
        case KNIGHT:
            if (!m.getWhiteMove().takes)
            {
                std::cout << "N" << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "Nx" << col << m.getWhiteMove().row + 1;
            }
            break;
        case BISHOP:
            if (!m.getWhiteMove().takes)
            {
                std::cout << "B" << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "Bx" << col << m.getWhiteMove().row + 1;
            }
            break;
        case KING:
            if (!m.getWhiteMove().takes)
            {
                std::cout << "K" << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "Kx" << col << m.getWhiteMove().row + 1;
            }
            break;
        case QUEEN:
            if (!m.getWhiteMove().takes)
            {
                std::cout << "Q" << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "Qx" << col << m.getWhiteMove().row + 1;
            }
            break;
        case PAWN:
            if (!m.getWhiteMove().takes)
            {
                std::cout << col << m.getWhiteMove().row + 1;
            }
            else
            {
                std::cout << "x" << col << m.getWhiteMove().row + 1;
            }
            break;
        }
    }
    else // color is black
    {
        col = (m.getBlackMove().column == ChessCol::A) ? 'A' : (m.getBlackMove().column == ChessCol::B) ? 'B' : (m.getBlackMove().column == ChessCol::C) ? 'C' :
            (m.getBlackMove().column == ChessCol::D) ? 'D' : (m.getBlackMove().column == ChessCol::E) ? 'E' : (m.getBlackMove().column == ChessCol::F) ? 'F' :
            (m.getBlackMove().column == ChessCol::G) ? 'G' : 'H';

        switch (m.getBlackMove().piece)
        {
        case ROOK:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\tR" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tRx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        case KNIGHT:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\tN" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tNx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        case BISHOP:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\tB" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tBx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        case KING:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\tK" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tKx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        case QUEEN:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\tQ" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tQx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        case PAWN:
            if (!m.getBlackMove().takes)
            {
                std::cout << "\t" << col << m.getBlackMove().row + 1 << std::endl;
            }
            else
            {
                std::cout << "\tx" << col << m.getBlackMove().row + 1 << std::endl;
            }
            break;
        }
    }
}


void  Run::move(Board* gameBoard, sf::Vector2f mouse, Piece* piece, int* state)
{
    ChessCol col = ChessCol::A;
    int row = 1;
    bool didMove = false, takes = false;
    Piece* goodbyePiece = nullptr;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (gameBoard->getSquares((ChessCol)i, j)->getGlobalBounds().contains(mouse) &&
                gameBoard->getSquares((ChessCol)i, j)->getState() == ACTIVE)
            {
                col = (ChessCol)i;
                row = j;
                didMove = true;
                takes = gameBoard->getSquares((ChessCol)i, j)->getOccupied();
                if (takes)
                {
                    goodbyePiece = gameBoard->getSquares((ChessCol)i, j)->getOccupyingPiece();
                    goodbyePiece->setPosition(sf::Vector2f(1100, 1100));
                    if (dynamic_cast<King*>(goodbyePiece) && goodbyePiece->getColor() == "White") // Black wins
                    {
                        *state = 2;
                    }
                    else if (dynamic_cast<King*>(goodbyePiece) && goodbyePiece->getColor() == "Black") // White wins
                    {
                        *state = 3;
                    }
                }
                goto out; // To Exit loop
            }
        }
    }

out:
    if (!didMove) return;

    if (clicked == PAWN) dynamic_cast<Pawn*>(piece)->addMove(); // If Pawn add move (so not repeating first move)

    Move m;

    if (piece->getColor() == "White") // whites turn
    {
        WhiteMove wm;
        wm.column = col;
        wm.prevCol = piece->getColumn();
        wm.row = row;
        wm.prevRow = piece->getRow();
        wm.piece = clicked;
        wm.takes = takes;
        m.setWhiteMove(wm);
        turn = "Black";
    }
    else // blacks turn
    {
        BlackMove bm;
        bm.column = col;
        bm.prevCol = piece->getColumn();
        bm.row = row;
        bm.prevRow = piece->getRow();
        bm.piece = clicked;
        bm.takes = takes;
        m.setBlackMove(bm);
        turn = "White";
    }

    piece->moveTo(col, row, *gameBoard);
    gameBoard->deactivateSquares();

    moves.push(m);
    printMove(m, piece);

    clicked = NONE;
}

void Run::initializePieces(Board& gameBoard)
{
    turn = "White";
    switch (mode)
    {
    case STANDARD:
        blackKnight1.moveTo(ChessCol::B, 7, gameBoard);
        blackKnight2.moveTo(ChessCol::G, 7, gameBoard);
        whiteKnight1.moveTo(ChessCol::B, 0, gameBoard);
        whiteKnight2.moveTo(ChessCol::G, 0, gameBoard);

        blackRook1.moveTo(ChessCol::A, 7, gameBoard);
        blackRook2.moveTo(ChessCol::H, 7, gameBoard);
        whiteRook1.moveTo(ChessCol::A, 0, gameBoard);
        whiteRook2.moveTo(ChessCol::H, 0, gameBoard);

        blackQueen.moveTo(ChessCol::E, 7, gameBoard);
        whiteQueen.moveTo(ChessCol::E, 0, gameBoard);

        blackKing.moveTo(ChessCol::D, 7, gameBoard);
        whiteKing.moveTo(ChessCol::D, 0, gameBoard);

        blackBishop1.moveTo(ChessCol::C, 7, gameBoard);
        blackBishop2.moveTo(ChessCol::F, 7, gameBoard);
        whiteBishop1.moveTo(ChessCol::C, 0, gameBoard);
        whiteBishop2.moveTo(ChessCol::F, 0, gameBoard);

        wPawn1.moveTo(ChessCol::A, 1, gameBoard);
        wPawn2.moveTo(ChessCol::B, 1, gameBoard);
        wPawn3.moveTo(ChessCol::C, 1, gameBoard);
        wPawn4.moveTo(ChessCol::D, 1, gameBoard);
        wPawn5.moveTo(ChessCol::E, 1, gameBoard);
        wPawn6.moveTo(ChessCol::F, 1, gameBoard);
        wPawn7.moveTo(ChessCol::G, 1, gameBoard);
        wPawn8.moveTo(ChessCol::H, 1, gameBoard);

        bPawn1.moveTo(ChessCol::A, 6, gameBoard);
        bPawn2.moveTo(ChessCol::B, 6, gameBoard);
        bPawn3.moveTo(ChessCol::C, 6, gameBoard);
        bPawn4.moveTo(ChessCol::D, 6, gameBoard);
        bPawn5.moveTo(ChessCol::E, 6, gameBoard);
        bPawn6.moveTo(ChessCol::F, 6, gameBoard);
        bPawn7.moveTo(ChessCol::G, 6, gameBoard);
        bPawn8.moveTo(ChessCol::H, 6, gameBoard);

        wPawn1.resetMove();
        wPawn2.resetMove();
        wPawn3.resetMove();
        wPawn4.resetMove();
        wPawn5.resetMove();
        wPawn6.resetMove();
        wPawn7.resetMove();
        wPawn8.resetMove();

        bPawn1.resetMove();
        bPawn2.resetMove();
        bPawn3.resetMove();
        bPawn4.resetMove();
        bPawn5.resetMove();
        bPawn6.resetMove();
        bPawn7.resetMove();
        bPawn8.resetMove();

        break;
    case RANDOM:
       //Under construction
        break;
    }
}

void Run::DrawPieces(sf::RenderWindow* window)
{
    // White Pawns
    window->draw(wPawn1);
    window->draw(wPawn2);
    window->draw(wPawn3);
    window->draw(wPawn4);
    window->draw(wPawn5);
    window->draw(wPawn6);
    window->draw(wPawn7);
    window->draw(wPawn8);

    // Black Pawns
    window->draw(bPawn1);
    window->draw(bPawn2);
    window->draw(bPawn3);
    window->draw(bPawn4);
    window->draw(bPawn5);
    window->draw(bPawn6);
    window->draw(bPawn7);
    window->draw(bPawn8);
    
    // Bishops
    window->draw(blackBishop1);
    window->draw(blackBishop2);
    window->draw(whiteBishop1);
    window->draw(whiteBishop2);

    // Knight
    window->draw(blackKnight1);
    window->draw(blackKnight2);
    window->draw(whiteKnight1);
    window->draw(whiteKnight2);

    // Rooks
    window->draw(blackRook1);
    window->draw(blackRook2);
    window->draw(whiteRook1);
    window->draw(whiteRook2);

    // Queens
    window->draw(blackQueen);
    window->draw(whiteQueen);

    // Kings
    window->draw(blackKing);
    window->draw(whiteKing);
}

void Run::clickedMain(sf::Vector2f mouse, int* state)
{
    if (Standard->getGlobalBounds().contains(mouse)) // Activates Standard Mode
    {
        mode = STANDARD;
        *state = 1;
        std::cout << "---Game Mode: Standard---" << std::endl << "White:\tBlack:" << std::endl;
    }
    else if (Randomized->getGlobalBounds().contains(mouse)) // Activates Randomized Mode
    {
        //mode = RANDOM;
        *state = 1;
        std::cout << "---Game Mode: Random---" << std::endl << "White:\tBlack:" << std::endl;
        Back->underConstruction(underConstruction);
    }
}

void Run::clickedGame(Piece* p, sf::Vector2f& mouse, int* state, Board& gameBoard)
{
    gameBoard.deactivateSquares();
    selectedPiece = p;

    if (dynamic_cast<Pawn*>(p)) clicked = PAWN;
    else if (dynamic_cast<Rook*>(p)) clicked = ROOK;
    else if (dynamic_cast<Knight*>(p)) clicked = KNIGHT;
    else if (dynamic_cast<Bishop*>(p)) clicked = BISHOP;
    else if (dynamic_cast<Queen*>(p)) clicked = QUEEN;
    else if (dynamic_cast<King*>(p)) clicked = KING;

    selectedPiece->movementSquares(gameBoard);
}


void Run::loadTextures()
{
    if (!undoButton.loadFromFile("Undo.png")) std::cout << "error!!!!!!!!!!!!!!!!!!!!!!!!!!";
    Backtext.loadFromFile("BackButton.png");
    standard.loadFromFile("Standard.png");
    random.loadFromFile("Random.png");
    backDrop.loadFromFile("BackDrop.png");
    welcome.loadFromFile("WelcomeBackDrop.png");
    whiteWins.loadFromFile("WhiteWins.png");
    blackWins.loadFromFile("BlackWins.png");
    underConstruction.loadFromFile("UnderConstruction.png");
}

