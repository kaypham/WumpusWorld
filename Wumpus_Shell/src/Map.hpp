/// <summary>
//	To record the path agent has taken
//  To describe the environment of each cell 
/// </summary>

// TODO: How to get size of map? Or does it matter?
// As we also know the the size of the board is 10 x 10 max, have a vector of 10 vectors of 10 cells. That way as the agent moves around the board, we can simply do Map[x][y] to update Map

#ifndef MAP
#define MAP

#include <vector>

using namespace std;

// Describes the findings of each node
struct Cell
{
	bool breeze; // used if pit or wumpus is 100% present?
	bool stench;
	bool visited;
	float pitPresent;
	float wumpusPresent;
	int x, y;
};

// Keep track of the path agent has taken
class Map
{
private:

public:
	// First vector is the x axis, second vector is the y axis. Bottom left most Cell is (0,0), Y increases moving up,
	// and X increases moving right.
	vector< vector<Cell> > map;

	// constructor
	Map();

	// After every move, call methods that can determine potential hazards in adjacent 
	// judging from the map we have so far.
	// Maybe not early in the game when the agent only makes a couple moves.
	void Locate_Pit_And_Wumpus();

};

#endif //MAP
