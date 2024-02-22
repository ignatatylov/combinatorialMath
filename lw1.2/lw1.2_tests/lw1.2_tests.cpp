#include <iostream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../lw1.2/MaxCostBag.h"	

using namespace std;

SCENARIO("MaxCostBag")
{
	WHEN("INPUT matrix is empty")
	{
		ostringstream output;
		THEN("OUTPUT is empty")
		{		
			vector<vector<int>> objects = { {} };
			vector<int>inBag = MaxCostBag(objects, 0);
			copy(inBag.begin(), inBag.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str().empty());
		}
	}
	WHEN("INPUT matrix is correct")
	{
		ostringstream output;
		THEN("OUTPUT is correct")
		{
			vector<vector<int>> objects = { {1, 1, 1},
										    {2, 2, 2},
										    {3, 3, 3},
										    {4, 4, 4} };
			int limit = 5;
			vector<int>inBag = MaxCostBag(objects, limit);
			copy(inBag.begin(), inBag.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "1 4 ");
		}
	}
	WHEN("INPUT matrix is correct")
	{
		ostringstream output;
		THEN("OUTPUT is correct")
		{
			vector<vector<int>> objects = { {1, 1, 1},
											{2, 2, 2},
											{3, 3, 3},
											{4, 4, 4} };
			int limit = 500;
			vector<int>inBag = MaxCostBag(objects, limit);
			copy(inBag.begin(), inBag.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "1 2 3 4 ");
		}
	}
}