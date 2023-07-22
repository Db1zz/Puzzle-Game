#include "Tile.h"

int Tile::getNum() { return m_tile; }

bool Tile::isEmpty() { return m_tile == 0; }

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	if (tile.m_tile > 9)
		out << " " << tile.m_tile << " ";
	else if (tile.m_tile > 0)
		out << "  " << tile.m_tile << " ";
	else if (tile.m_tile == 0)
		out << "    ";
	return out;
}

bool operator==(const Tile& t1, const Tile& t2)
{
	return t1.m_tile == t2.m_tile;
}

//bool operator!=(const Tile& t1, const Tile& t2)
//{
//	return !(t1.m_tile == t2.m_tile);
//}