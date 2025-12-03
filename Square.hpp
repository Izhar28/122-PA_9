#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

typedef enum column
{
	A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7
} Column;

typedef enum state
{
	IDLE = 0, ACTIVE = 1
} State;

class Square : public sf::RectangleShape
{
public:
	Square();
	~Square();

	Column getColumn() const;
	int getRow() const;
	sf::Vector2f getPos() const;
	std::string getColor() const;
	bool getOccupied() const;
	std::string getOccupiedColor() const;
	State getState() const;


	void setColumn(Column const newColumn);
	void setRow(int const newRow);
	void setPos(sf::Vector2f const newPos);
	void setColor(std::string const newColor);
	void setOccupiedColor(std::string const newColor);
	void setOccupied(bool const newOcc);
	void setState(State const newState);

private:
	Column column;
	int row;
	sf::Vector2f pos;
	std::string color, occupiedColor;
	bool occupied;
	State state;

	sf::Texture white;
	sf::Texture black;
	sf::Texture activeWhite;
	sf::Texture activeBlack;
};