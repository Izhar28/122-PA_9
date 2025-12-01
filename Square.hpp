#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Square : public sf::RectangleShape
{
public:
	Square();
	~Square();

	char getColumn() const;
	int getRow() const;
	sf::Vector2f getPos() const;
	sf::Color getColor() const;


	void setColumn(char const newColumn);
	void setRow(int const newRow);
	void setPos(sf::Vector2f const newPos);
	void setColor(sf::Color const newColor);

private:
	char column;
	int row;
	sf::Vector2f pos;
	sf::Color color;
};