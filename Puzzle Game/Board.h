#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "Tile.h"
#include "Point.h"
class Direction;

class Board
{
public:
	static constexpr int SIZE = 4; // Size of board

	int totalMoves{ 0 }; // Move counter

	static void printEmptyLine(int lines) 
	{
		for (int i{ 0 }; i < lines; ++i)
			std::cout << std::endl;
	}

	Board() = default;

	void moveTile(Direction dir);
	void swapTiles(Point& p1, Point& p2);
	bool boundary(Point& p1);
	void randomize();
	bool winCondtion();

	friend std::ostream& operator<<(std::ostream& out, const Board& board);
	friend bool operator==(const Board& b1, const Board& b2);

private:
	Tile m_tiles[SIZE][SIZE]
	{
	{ 1 , 2 , 3 , 4 },
	{ 5 , 6 , 7 , 8 },
	{ 9 , 10, 11, 12},
	{ 13, 14, 15, 0 }
	};
};
#endif // !BOARD_H
