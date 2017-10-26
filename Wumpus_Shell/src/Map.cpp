
//Cell Map::getCellUp(int x, int y)
//{
	//try{
	//	return map.at(x).at(y+1);
	//}
	//catch(const std::out_of_range& oor){
	//	std::cout << "ERROR: Map location doesn't exist " << oor.what() << std::endl;
	//	throw oor;
	//}
//}
#include <iostream>
#include "Map.hpp"

using namespace std;

Map::Map()
{
	for(int x=0; x<10; x++)
	{
		map.push_back(vector<Cell>());		
		for(int y=0; y<10; y++)
		{
			Cell c = {0};
			c.x = x;
			c.y = y;
			map[x].push_back(c);
		}
	}
}

vector<Cell*> Map::getAdjacentCells(int x, int y)
{
	vector<Cell*> cells;
	// make sure cell location is within bounds
	if(x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		// get Left
		if(x > 0) // can't get left if 0
		{
			cells.push_back( &map.at(x-1).at(y) );
		}
		// get Down
		if(y > 0) // can't get down if 0
		{
			cells.push_back( &map.at(x).at(y) );
		}

		// (note) for right and up, boundaries of actualworld may be smaller, but in that case, adjacent walls will be marked with a wall indication.
		// get Right
		if(x < 9) // can't get right if 9
		{
			cells.push_back( &map.at(x+1).at(y) );
		}
		// get Left
		if(y < 9) // can't get left if 9
		{
			cells.push_back( &map.at(x).at(y+1) );
		}
	}
	else
	{
		throw out_of_range("Map location out of bounds");
	}

	return cells;
}

