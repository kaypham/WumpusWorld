#include <vector> 

using namespace std;

// Describes the findings of each node
class Cell
{
	bool visited;
	float wumpusPresent;
	float pitPresent;
};

// Keep track of the path agent has taken
class Map
{
	vector<vector<Cell>> map;
};
