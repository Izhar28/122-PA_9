#include "Square.hpp"

sf::Texture Square::blackSquare, Square::whiteSquare, Square::activeWhite, Square::activeBlack;

Square::Square() : sf::RectangleShape(sf::Vector2f(100, 100)), column(ChessCol::A), row(0), occupied(false), state(IDLE)
{
	setPosition(sf::Vector2f(0, 0));
	setFillColor(sf::Color::White);
	color = "White";
	occupiedColor = "None";
	occupyingPiece = nullptr;
}

Square::~Square()
{
}

void Square::loadTextures()
{
	whiteSquare.loadFromFile("white.png");
	blackSquare.loadFromFile("black.png");
	activeWhite.loadFromFile("ActiveWhite.png");
	activeBlack.loadFromFile("ActiveBlack.png");
}


ChessCol Square::getColumn() const
{
	return column;
}

int Square::getRow() const
{
	return row;
}

sf::Vector2f Square::getPos() const
{
	return pos;
}

std::string Square::getColor() const
{
	return color;
}

bool Square::getOccupied() const
{
	return occupied;
}

std::string Square::getOccupiedColor() const
{
	return occupiedColor;
}

Piece* Square::getOccupyingPiece() const
{
	return occupyingPiece;
}

State Square::getState() const
{
	return state;
}

void Square::setColumn(ChessCol const newColumn)
{
	if (newColumn == ChessCol::A || newColumn == ChessCol::B || newColumn == ChessCol::C || newColumn == ChessCol::D || newColumn == ChessCol::E || newColumn == ChessCol::F || newColumn == ChessCol::G || newColumn == ChessCol::H)
	{
		column = newColumn;
	}
}

void Square::setRow(int const newRow)
{
	if (newRow > 0 && newRow < 9)
	{
		row = newRow;
	}
}

void Square::setPos(sf::Vector2f const newPos)
{
	pos = newPos;
	setPosition(pos);
}

void Square::setColor(std::string const newColor)
{
	color = newColor;
}

void Square::setOccupiedColor(std::string const newColor)
{
	occupiedColor = newColor;
}

void Square::setOccupied(bool const newOcc)
{
	occupied = newOcc;
}

void Square::setOccupyingPiece(Piece* const newPiece)
{
	occupyingPiece = newPiece;
}

void Square::setState(State const newState)
{
	state = newState;

	switch (state)
	{
	case IDLE:
		if (color == "White")
			setTexture(&whiteSquare);
		else
			setTexture(&blackSquare);
		break;
	case ACTIVE:
		if (color == "White")
			setTexture(&activeWhite);
		else
			setTexture(&activeBlack);
		break;
	}
}