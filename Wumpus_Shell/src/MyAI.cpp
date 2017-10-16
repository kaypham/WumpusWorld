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
#include "MyAI.hpp"
#include "Map.hpp"

using namespace std;

MyAI::MyAI() : Agent()
{
	// ======================================================================
	// YOUR CODE BEGINS
	// ======================================================================
	
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
		return CLIMB;
	}
	if (stench)
	{
		cout << "There is a stench" << endl;
	}	
	if (breeze)
	{
		cout << "There is a breeze " << endl;
	}
	if (bump)
	{
		cout << "There is a wall" << endl;
	}
	return TURN_LEFT;
	// ======================================================================
	// YOUR CODE ENDS
	// ======================================================================
}

// ======================================================================
// YOUR CODE BEGINS
// ======================================================================


// ======================================================================
// YOUR CODE ENDS
// ======================================================================
