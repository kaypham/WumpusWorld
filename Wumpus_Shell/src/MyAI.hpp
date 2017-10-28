// ======================================================================
// FILE:        MyAI.hpp
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

#ifndef MYAI_LOCK
#define MYAI_LOCK

#include <tuple>
#include <vector>
#include "Agent.hpp"
#include "Map.hpp"
#include "ProbHandle.hpp"

class MyAI : public Agent
{
public:
	MyAI ( void );
	
	Action getAction
	(
		bool stench,
		bool breeze,
		bool glitter,
		bool bump,
		bool scream
	);
	
	// ======================================================================
	// YOUR CODE BEGINS
	// ======================================================================
	bool isBackTracking = false;

	int loc[2];	
	Map board;
	ProbHandle wumpusProb;

	// takes as input a location for the AI and returns a value. The larger the number, the better the position
	int evaluateMove(int* loc);

	// given a vector of cells representing positions for the AI, return the location of the best move
	std::tuple<int, int> bestMove(vector<Cell*> moves);
	
	Action backTrack();
	// ======================================================================
	// YOUR CODE ENDS
	// ======================================================================
};

#endif
