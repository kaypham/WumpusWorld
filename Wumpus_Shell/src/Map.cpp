
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
