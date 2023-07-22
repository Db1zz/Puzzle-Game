#ifndef DIRECTION_H
#define DIRECTION_H

class Board;
class Point;

#include <iostream>

class Direction
{
public:
	enum Type
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,

		max_directions
	};
private:
	Type m_direction{};

public:
	Direction(char ch);
	Direction(Type dir);
	Type charToDirection(char ch);
	static Direction randomDirection();

	friend std::ostream& operator<<(std::ostream& stream, const Direction& dir);
	Direction operator-() const;
	friend class Board;
	friend class Point;
};
#endif // !DIRECTION_H