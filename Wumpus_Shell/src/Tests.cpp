#ifndef MYTESTS
#define MYTESTS

#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Map.cpp"
#include "ProbHandle.hpp"
#include "ProbHandle.cpp"


namespace Tests
{
	// map constructor test
	bool mapConstructorTest()
	{
		bool condition = true;
		Map m;

		for(int x=0; x<10; x++)
		{
			for(int y=0; y<10; y++)
			{
				if(m.map[x][y].breeze != false)
				{
					condition = false;
				}
			}
		}
		return condition;
	}

	//getAdjacentCells test
	bool mapGetAdjacentTestOne()
	{
		bool condition = true;
		Map m;
		std::vector<Cell*> cells;		

		m.getAdjacentCells(5,5, cells);
		
		if(cells.size() != 4)
		{
			condition = false;
		}
		cells.erase(cells.begin(), cells.end());
		m.getAdjacentCells(0,0, cells);
		if(cells.size() != 2)
		{
			condition = false;
		}
		cells.erase(cells.begin(), cells.end());
		m.getAdjacentCells(9,9, cells);
		if(cells.size() != 2)
		{
			condition = false;
		}
		return condition;
	}

	// test basic functionality of adding cells to ProbHandle object
	bool probHandleTestOne()
	{
		bool condition = true;
		Map m;
		ProbHandle p;
		std::vector<Cell*> cells;		
		m.getAdjacentCells(5, 5, cells);
		p.addSuspects(cells);
		
		if(	(int)m.map[4][5].wumpusPresent != 25 &&
			(int)m.map[6][5].wumpusPresent != 25)
		{
			condition = false;
		}

		return condition;
	}

	// test basic functionality of adding cells to ProbHandle object
	bool probHandleTestTwo()
	{
		bool condition = true;
		Map m;
		ProbHandle p;

		std::vector<Cell*> cells;
		m.getAdjacentCells(5, 5, cells);

		p.addSuspects(cells);
		p.removeSuspects(cells);
		if(p.suspectNumber() != 0)
		{
			condition = false;
		}

		return condition;
	}

	// test basic functionality of adding cells, removing some, and returning correct probabilies
	bool probHandleTestThree()
	{
		bool condition = true;
		Map m;
		ProbHandle p;
		std::vector<Cell*> cells;
		std::vector<Cell*> other_cells;
		m.getAdjacentCells(5, 5, cells);
		m.getAdjacentCells(3, 5, other_cells);

		p.addSuspects(cells);
		p.removeSuspects(other_cells);
		if(p.suspectNumber() != 3)
		{
			condition = false;
		}
		if((int)m.map[5][6].wumpusPresent != 33)
		{
			std::cout << "probability = " << m.map[5][6].wumpusPresent << std::endl;
			condition = false;
		}

		return condition;
	}

	void run_all()
	{
		std::vector<bool (*)()> tests;

		//add tests
		tests.push_back(mapConstructorTest);
		tests.push_back(mapGetAdjacentTestOne);
		tests.push_back(probHandleTestOne);
		tests.push_back(probHandleTestTwo);
		tests.push_back(probHandleTestThree);
		
		std::cout << "running tests" << std::endl;

		for(int i=0; i < tests.size(); i++)
		{
			// run functions
			if( tests.at(i)() )
			{
				std::cout << "PASS" << std::endl;
			}
			else
			{
				std::cout << "FAIL" << std::endl;
			}
		}
	}
}

// this main is only for running tests
int main()
{
	// run all existing tests	
	Tests::run_all();

	return 0;
}


#endif //MYTESTS
