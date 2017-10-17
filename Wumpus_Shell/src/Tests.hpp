#ifndef MYTESTS
#define MYTESTS

#include <vector>
#include <iostream>
#include "Map.hpp"


namespace Tests
{
	inline bool mapConstructorTest()
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

	inline void run_all()
	{
		std::vector<bool (*)()> tests;

		//add tests
		tests.push_back(mapConstructorTest);
	
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
