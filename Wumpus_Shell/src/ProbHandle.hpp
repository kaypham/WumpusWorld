#ifndef PROBHANDLE
#define PROBHANDLE

#include <vector>

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

// this can be used to help identify the square with the Wumpus. It will keep track of the suspected cells
// for Wumpus location and ensure the sum of probability is 1 or 100% between all of them. When a cell is
// removed and no longer a culprit cell, the probabilities will be redistributed among the remaining cells.
//
// This will only work for the Wumpus I think, because there is only 1 in the whole map. There can be more that 1 pit.
// Pits will need to be handled differently.
class ProbHandle
{
private:
	// used internally to re-calculate probabilities when a change in suspects occurs
	void calcProb();

public:
	// culprit cells in hash table
	std::vector<Cell*> suspects;

	// returns the number of existing suspect cells
	int suspectNumber();

	// adds new cells to suspects and modifies the distributed probability among the cells
	void addSuspects(std::vector<Cell*> cells);

	// if a cell in this list is a pointer to a cell in the suspects, remove it
	void removeSuspects(std::vector<Cell*> cells);
};


#endif //PROBHANDLE
