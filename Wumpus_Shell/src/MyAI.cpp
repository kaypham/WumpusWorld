// ======================================================================
// FILE:        MyAI.cpp
//
// AUTHOR:      Abdullah Younis
//
// DESCRIPTION: This file contains your agent class, which you will
//              implement. You are responsible for implementing the
//              'getAction' function and any helper methods you feel you
//              need.
//
// NOTES:       - If you are having trouble understanding how the shell
//                works, look at the other parts of the code, as well as
//                the documentation.
//
//              - You are only allowed to make changes to this portion of
//                the code. Any changes to other portions of the code will
//                be lost when the tournament runs your code.
// ======================================================================

#include <iostream>
#include <typeinfo>
#include "MyAI.hpp"


MyAI::MyAI() : Agent()
{
	// ======================================================================
	// YOUR CODE BEGINS
	// ======================================================================
	loc[0] = 0;
	loc[1] = 0;
	// ======================================================================
	// YOUR CODE ENDS
	// ======================================================================
}
	
// At every cell, agent only feels stench, breeze, and glitter.
// At every cell, this function will get called
Agent::Action MyAI::getAction
(
	bool stench,
	bool breeze,
	bool glitter,
	bool bump,
	bool scream
)
{
	// ======================================================================
	// YOUR CODE BEGINS
	// ======================================================================
	if (glitter)
	{	
		isBackTracking = true;
		return GRAB;	// grab the gold
	}
	if (isBackTracking)
	{
		return backTrack();
	}
	if (stench)
	{
		std::cout << "There is a stench" << std::endl;
		// get adjacent spaces and assign probabilities to them
		//wumpusProb.addSuspects( board.getAdjacentCells(loc[0], loc[1]) );
	}
	else	// if no stench is detected...
	{
		// remove suspect spaces if possible
		std::vector<Cell*> adj_cells;
		std::cout << wumpusProb.suspectNumber() << std::endl;
		//board.getAdjacentCells(loc[0], loc[1], adj_cells);
		//wumpusProb.removeSuspects(adj_cells);
	}
	if (breeze)
	{
		std::cout << "There is a breeze " << std::endl;
	}
	if (bump)
	{
		std::cout << "There is a wall" << std::endl;
	}
	return TURN_LEFT;
	// ======================================================================
	// YOUR CODE ENDS
	// ======================================================================
}

// ======================================================================
// YOUR CODE BEGINS
// ======================================================================

int MyAI::evaluateMove(int* loc)
{
	Cell* pos = board.getCell(loc[0], loc[1]);
	
	if(pos->wumpusPresent > 0 || pos->pitPresent > 0)
	{
		// don't take the chance for now
		return 0;	
	}
	if((int)(pos->wumpusPresent) == 0 && (int)(pos->pitPresent) == 0)
	{
		// value bettern than 0
		return 10;
	}
}

std::tuple<int,int> MyAI::bestMove(std::vector<Cell*> moves)
{
	if(moves.size() != 0)
	{
		Cell* best = moves.at(0);
		int best_val = 0;
		int temp = 0;
		int temp_loc[2] = {0,0};
		int best_loc[2];
		for(std::vector<Cell*>::iterator i=moves.begin(); i != moves.end(); i++)
		{
			temp_loc[0] = (*i)->x; temp_loc[1] = (*i)->y;
			temp = evaluateMove(temp_loc);
			if(temp > best_val)
			{
				best_val = temp;
				best = *i;
				best_loc[0] = temp_loc[0]; best_loc[1] = temp_loc[1];
			}
		}
		return make_tuple(best_loc[0], best_loc[1]);
	}	
	// just return current AI loc if moves is empty
	// can change this later if we want to...
	return make_tuple(loc[0], loc[1]);
}

// This will call back_track function where it will use the path it comes from
// to climb out of the maze
// Note: agent can only climb out at cell (0, 0)
Agent::Action MyAI::backTrack()
{
}

// ======================================================================
// YOUR CODE ENDS
// ======================================================================
