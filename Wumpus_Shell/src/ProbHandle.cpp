#include "ProbHandle.hpp"
#include <iostream>


void ProbHandle::calcProb()
{
	double prob = 1; // default prob if there are no suspects
	if(suspects.size() != 0)
	{
		prob = 100 / suspects.size();
	}
	// reset wumpus probabilities to new value
	for(std::vector<Cell*>::iterator i=suspects.begin(); i<suspects.end(); i++)
	{
		(*i)->wumpusPresent = prob;
	}
}


int ProbHandle::suspectNumber()
{
	return suspects.size();
}


void ProbHandle::addSuspects(std::vector<Cell*> cells)
{
	suspects.insert(suspects.end(), cells.begin(), cells.end());

	calcProb();
}


void ProbHandle::removeSuspects(std::vector<Cell*> cells)
{
	//double for loop not too good. suspects maybe should be a table
	for(int i=0; i<cells.size(); i++)
	{
		for(int j=0; j<suspects.size(); j++)
		{
			if(suspects[j]->x == cells[i]->x && suspects[j]->y == cells[i]->y)
			{
				suspects.erase(suspects.begin()+j);
				break;
			}
		}
	}
	
	calcProb();
}
