/// <summary>
//	To record the path agent has taken
//  To describe the environment of each cell 
/// </summary>

// TODO: How to get size of map? Or does it matter?
// As we also know the the size of the board is 10 x 10 max, have a vector of 10 vectors of 10 cells. That way as the agent moves around the board, we can simply do Map[x][y] to update Map

#include <vector> 

using namespace std;

// Describes the findings of each node
class Cell
{
	bool breeze;
	bool stench;
	bool visited;
	float pitPresent;
	float wumpusPresent;
};

// Keep track of the path agent has taken
class Map
{
	vector<vector<Cell>> map;
	
	// After every move, call methods that can determine potential hazards in adjacent 
	// judging from the map we have so far.
	// Maybe not early in the game when the agent only makes a couple moves.
	
	void Locate_Pit_And_Wumpus();
};
