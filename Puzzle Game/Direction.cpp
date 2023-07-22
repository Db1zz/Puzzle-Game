#include "Direction.h"
#include <cassert>
#include <cstdlib>
#include "Board.h"
#include "Random.h"

Direction::Direction(char ch)
{
	m_direction = charToDirection(ch);
}
Direction::Direction(Type dir)
{
	m_direction = dir;
}
Direction::Type Direction::charToDirection(char ch)
{
	switch (ch)
	{
	case 'w': return UP;
	case 's': return DOWN;
	case 'd': return RIGHT;
	case 'a': return LEFT;
	}
	return UP;
}

Direction Direction::randomDirection()
{
	int randomNumber = Random::get(0, (Type::max_directions - 1));

	return static_cast<Type>(randomNumber);
}

Direction Direction::operator-() const
{
	switch (m_direction)
	{
	case UP: return Direction{ DOWN };
	case DOWN: return Direction{ UP };
	case LEFT: return Direction{ RIGHT };
	case RIGHT: return Direction{ LEFT };
	default:
		assert(0 && "Unsupported direction was passed!");
		return Direction{ UP };
	}
}

std::ostream& operator<<(std::ostream& stream, const Direction& dir)
{
	switch (dir.m_direction)
	{
	case Direction::UP: return stream << "up";
	case Direction::DOWN: return stream << "down";
	case Direction::LEFT: return stream << "left";
	case Direction::RIGHT: return stream << "right";
	}
	return stream;
}

