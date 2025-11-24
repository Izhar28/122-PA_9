#include "Coord.hpp"

Coord::Coord()
{
	column = 'A';
	row = 1;
	color = sf::Color::Blue;
}

Coord::~Coord()
{

}

char Coord::getColumn() const
{
	return column;
}

int Coord::getRow() const
{
	return row;
}

sf::Color Coord::getColor() const
{
	return color;
}

void Coord::setColumn(char const newColumn)
{
	if (newColumn == 'A' || newColumn == 'B' || newColumn == 'C' || newColumn == 'D' || newColumn == 'E' || newColumn == 'F' || newColumn == 'G' || newColumn == 'H')
	{
		column = newColumn;
	}
}

void Coord::setRow(int const newRow)
{
	if (newRow > 0 && newRow < 9)
	{
		row = newRow;
	}
}

void Coord::setColor(sf::Color const newColor)
{
	color = newColor;
}