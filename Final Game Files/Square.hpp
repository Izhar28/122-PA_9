#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Types.hpp"

class Piece; // forward declaration


class Square : public sf::RectangleShape
{
public:
	Square();
	~Square();

	static void loadTextures();

	ChessCol getColumn() const;
	int getRow() const;
	sf::Vector2f getPos() const;
	std::string getColor() const;
	bool getOccupied() const;
	std::string getOccupiedColor() const;
	Piece* getOccupyingPiece() const;
	State getState() const;


	void setColumn(ChessCol const newColumn);
	void setRow(int const newRow);
	void setPos(sf::Vector2f const newPos);
	void setColor(std::string const newColor);
	void setOccupiedColor(std::string const newColor);
	void setOccupied(bool const newOcc);
	void setOccupyingPiece(Piece* const newPiece);
	void setState(State const newState);

private:
	ChessCol column;
	int row;
	sf::Vector2f pos;
	std::string color, occupiedColor;
	bool occupied;
	Piece* occupyingPiece;
	State state;

	static sf::Texture blackSquare, whiteSquare, activeWhite, activeBlack;
};