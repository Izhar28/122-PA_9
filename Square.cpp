#include "Square.hpp"

Square::Square() : sf::RectangleShape(sf::Vector2f(100, 100)), column(A), row(0), occupied(false), state(IDLE)
{
	setPosition(sf::Vector2f(0, 0));
	setFillColor(sf::Color::White);
	color = "White";
	occupiedColor = "None";
	if (!white.loadFromFile("white.png")) return;
	if (!black.loadFromFile("black.png")) return;
	if (!activeWhite.loadFromFile("ActiveWhite.png")) return;
	if (!activeBlack.loadFromFile("ActiveBlack.png")) return;
}

Square::~Square()
{
}


Column Square::getColumn() const
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

State Square::getState() const
{
	return state;
}

void Square::setColumn(Column const newColumn)
{
	if (newColumn == A || newColumn == B || newColumn == C || newColumn == D || newColumn == E || newColumn == F || newColumn == G || newColumn == H)
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

void Square::setState(State const newState)
{
	state = newState;

	switch (state)
	{
	case IDLE:
		if (color == "White")
			setTexture(&white);
		else
			setTexture(&black);
		break;
	case ACTIVE:
		if (color == "White")
			setTexture(&activeWhite);
		else
			setTexture(&activeBlack);
		break;
	}
}