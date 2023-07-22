#include <algorithm>
#include "Board.h"
#include "Point.h"
#include "Direction.h"
#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	constexpr int g_consoleLines{ 25 };
	board.printEmptyLine(g_consoleLines);

	for (int row{ 0 }; row < board.SIZE; ++row)
	{
		for (int column{ 0 }; column < board.SIZE; ++column)
		{
			out << board.m_tiles[row][column];
		}
		out << std::endl;
	}
	return out;
}

void Board::moveTile(Direction dir)
{
	Point number{ 0, 0 };
	static Point zero{ 3, 3 }; // x = 3, y = 3 coords of 0

	number = zero.getAdjacentPoint(-dir);
	if (boundary(number))
	{
		swapTiles(zero, number);
		zero = zero.getAdjacentPoint(-dir);
	}

}

void Board::swapTiles(Point& p1, Point& p2)
{
	std::swap(m_tiles[p1.m_row][p1.m_column], m_tiles[p2.m_row][p2.m_column]);
}

bool Board::boundary(Point& p1)
{
	return p1.m_column < SIZE 
		&& p1.m_column >= 0 
		&& p1.m_row < SIZE 
		&& p1.m_row >= 0;
}

void Board::randomize()
{
	constexpr int steps{ 1000 };
	for (int step{ 0 }; step < steps; ++step)
	{
		moveTile(Direction::randomDirection());
	}
}

bool Board::winCondtion()
{
	static Board s_solved{};
	return s_solved == *this;
}

bool operator==(const Board& b1, const Board& b2)
{
	for (int row{ 0 }; row < Board::SIZE; ++row)
		for (int column{ 0 }; column < Board::SIZE; ++column)
			if (b1.m_tiles[row][column] != b2.m_tiles[row][column])
				return false;

	return true;
}