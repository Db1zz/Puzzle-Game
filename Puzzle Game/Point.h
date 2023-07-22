#ifndef POINT_H
#define POINT_H

class Direction;
class Board;

class Point
{
	int m_column{ 0 };
	int m_row{ 0 };
public:
	Point() = default;

	Point(int column, int row);

	Point getAdjacentPoint(Direction dir);

	friend bool operator==(const Point& p1, const Point& p2);
	friend bool operator!=(const Point& p1, const Point& p2);

	friend class Board;
};

#endif // !POINT_H