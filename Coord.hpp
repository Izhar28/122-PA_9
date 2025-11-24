#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Coord
{
public:
	Coord();
	~Coord();

	char getColumn() const;
	int getRow() const;
	sf::Color getColor() const;

	void setColumn(char const newColumn);
	void setRow(int const newRow);
	void setColor(sf::Color const newColor);

private:
	char column;
	int row;
	sf::Color color;
};