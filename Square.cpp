#include "Square.hpp"

Square::Square() : sf::RectangleShape(sf::Vector2f(100, 100)), column('A'), row(1)
{
	setPosition(sf::Vector2f(0,0));
	setFillColor(sf::Color::White);
}

Square::~Square()
{

}


char Square::getColumn() const
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

sf::Color Square::getColor() const
{
	return color;
}

void Square::setColumn(char const newColumn)
{
	if (newColumn == 'A' || newColumn == 'B' || newColumn == 'C' || newColumn == 'D' || newColumn == 'E' || newColumn == 'F' || newColumn == 'G' || newColumn == 'H')
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

void Square::setColor(sf::Color const newColor)
{
	color = newColor;
	setFillColor(color);
}
