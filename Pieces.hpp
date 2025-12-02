#include <iostream>
#include <vector>
#include <memory>

class Board;

enum class Color
{
	White, Black
};

struct Position
{
	int row;
	int col;
	Position(int r = 0, int c = 0) :row(r), col(c) {}
};

class Piece
{
protected:
	Color color;
	Position pos;

public:
	Piece(Color c, Position p) : color(c), pos(p) {}
	virtual ~Piece() = default;

	Color getColor() const { return color; }
	Position getPosition() const { return pos; }
	void setPosition(Position p) { pos = p; }

	virtual std::vector<Position> getLegalMoves(const Board& board) const = 0;

	virtual char getSymbol() const = 0;
};

class King : public Piece
{
public:
	King(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'K' : 'k';
	}
};

class Rook : public Piece
{
public:
	Rook(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'R' : 'r';
	}
};

class Queen : public Piece
{
public:
	Queen(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'Q' : 'q';
	}
};

class Bishop : public Piece
{
public:
	Bishop(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'B' : 'b';
	}
};

class Knight : public Piece
{
public:
	Knight(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'Ki' : 'ki';
	}
};

class Pawn : public Piece
{
public:
	Pawn(Color c, Position p) : Piece(c, p) {}

	std::vector<Position> getLegalMoves(const Board& board) const override;

	char getSymbol() const override
	{
		return (color == Color::White) ? 'P' : 'p';
	}
};

std::vector<Position> King::getLegalMoves(const Board& board) const
{
	std::vector<Position> moves;
}
