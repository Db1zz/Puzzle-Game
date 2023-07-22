#include "Point.h"
#include "Direction.h"
#include "Board.h"
#include <cassert>



Point::Point(int column, int row)
	:m_column{ column }, m_row{ row }
{
}

Point Point::getAdjacentPoint(Direction dir)
{
	switch (dir.m_direction)
	{
	case Direction::UP:		return Point{ m_column,		m_row - 1 };
	case Direction::DOWN:	return Point{ m_column,		m_row + 1 };
	case Direction::LEFT:	return Point{ m_column - 1, m_row };
	case Direction::RIGHT:	return Point{ m_column + 1, m_row };
	default:
		// Should never occur.
		assert(0 && "Invalid direction input");
	}
	return *this;
}

// Overloaded operators
bool operator==(const Point& p1, const Point& p2)
{
	return p1.m_column == p2.m_column && p1.m_row == p2.m_row;
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}