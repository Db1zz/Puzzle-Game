#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
	int m_tile{ 0 };
public:
	Tile(int tile) : m_tile{ tile }
	{
	}
	int getNum();
	bool isEmpty();
	
	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
	friend bool operator==(const Tile& t1, const Tile& t2);
	//friend bool operator!=(const Tile& t1, const Tile& t2);
};

#endif // !TILES_H

