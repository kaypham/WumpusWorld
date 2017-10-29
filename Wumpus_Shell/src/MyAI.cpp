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
	dir = RIGHT;
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
	// find all adjacent cells to AI
	adj_cells.erase(adj_cells.begin(), adj_cells.end());
	board.getAdjacentCells(loc[0], loc[1], adj_cells);	

	if (glitter)
	{	
		cout << "gold!" << endl;
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
		wumpusProb.addSuspects(adj_cells);
		
	}
	else	// if no stench is detected...
	{
		// remove suspect spaces if possible
		wumpusProb.removeSuspects(adj_cells);
	}
	if (breeze)
	{
		std::cout << "There is a breeze " << std::endl;
	}
	if (bump)
	{
		std::cout << "There is a wall" << std::endl;
	}

	// decide what to do...
	tuple<int,int> space = bestMove(adj_cells);
	// turn and move foward to desired space...
	Agent::Action myMove = turnAndMove(space);
	cout << "move: ";
	switch(myMove)
	{
		case TURN_LEFT:
			cout << "left" << endl;
			break;
		case TURN_RIGHT:
			cout << "right" << endl;
			break;
		case FORWARD:
			cout << "forward" << endl;
			break;
	}
	return myMove;
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

tuple<int,int> MyAI::bestMove(std::vector<Cell*> moves)
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
			if(temp >= best_val)
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


Agent::Action MyAI::turnAndMove(tuple<int,int> space)
{
	//determine direction
	// DIRECTION UP
	if( get<0>(space) == loc[0] && get<1>(space) == loc[1]+1)
	{
		switch(dir)
		{
			case UP:
				return FORWARD;
			case DOWN:
				dir = RIGHT;
				return TURN_LEFT;
			case LEFT:
				dir = UP;
				return TURN_RIGHT;
			case RIGHT:
				dir = UP;
				return TURN_LEFT;
		}
	}
	// DIRECTION LEFT
	if( get<0>(space) == loc[0]-1 && get<1>(space) == loc[1])
	{
		switch(dir)
		{
			case UP:
				dir = LEFT;
				return TURN_LEFT;
			case DOWN:
				dir = LEFT;
				return TURN_RIGHT;
			case LEFT:
				return FORWARD;
			case RIGHT:
				dir = UP;
				return TURN_LEFT;
		}	
	}
	// DIRECTION RIGHT
	if( get<0>(space) == loc[0]+1 && get<1>(space) == loc[1])
	{
		switch(dir)
		{
			case UP:
				dir = RIGHT;
				return TURN_RIGHT;
			case DOWN:
				dir = RIGHT;
				return TURN_LEFT;
			case LEFT:
				dir = UP;
				return TURN_RIGHT;
			case RIGHT:
				return FORWARD;
		}	
	}
	// DIRECTION DOWN
	if( get<0>(space) == loc[0] && get<1>(space) == loc[1]-1)
	{
		switch(dir)
		{
			case UP:
				dir = RIGHT;
				return TURN_RIGHT;
			case DOWN:
				return FORWARD;
			case LEFT:
				dir = DOWN;
				return TURN_LEFT;
			case RIGHT:
				dir = DOWN;
				return TURN_RIGHT;
		}	
	}

	cout << "couldn't resolve desired direction :(" << endl;
	return FORWARD;
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
