#include <iostream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../lw1/findMinDistance.h"	

using namespace std;

SCENARIO("findMinDistance")
{
	WHEN("INPUT matrixs is empty")
	{
		ostringstream output;
		THEN("OUTPUT is also empty")
		{
			vector<int> v = { 0, 1, 2, 3 };
			vector<vector<int>> length = {};
			vector<vector<int>> weight = {};
			vector<int> minV = findMinDistance(v, length, weight);
			copy(minV.begin(), minV.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str().empty());
		}
	}
	WHEN("INPUT matrixs is not empty")
	{
		ostringstream output;
		THEN("OUTPUT is also empty")
		{
			vector<int> v = { 0, 1, 2, 3 };
			std::vector<std::vector<int>> length = { {0, 2, 3, 4},
											{2, 0, 5, 1},
											{3, 5, 0, 4},
											{4, 1, 4, 0} };
			std::vector<std::vector<int>> weight = { {0, 13, 10, 2},
													{13, 0, 12, 4},
													{10, 12, 0, 8},
													{2, 4, 8, 0} };
			vector<int> minV = findMinDistance(v, length, weight);
			copy(minV.begin(), minV.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "2 1 3 0 ");
		}
		THEN("OUTPUT is also empty")
		{
			vector<int> v = { 0, 1, 2, 3 };
			std::vector<std::vector<int>> length = { {0, 1, 1, 1},
											{1, 0, 1, 1},
											{1, 1, 0, 1},
											{1, 1, 1, 0} };
			std::vector<std::vector<int>> weight = { {0, 1, 1, 1},
													{1, 0, 1, 1},
													{1, 1, 0, 1},
													{1, 1, 1, 0} };
			vector<int> minV = findMinDistance(v, length, weight);
			copy(minV.begin(), minV.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "0 1 2 3 ");
		}
		THEN("OUTPUT is also empty")
		{
			vector<int> v = { 0, 1, 2, 3 };
			std::vector<std::vector<int>> length = { {0, 1, 1, 1},
											{1, 0, 1, 1},
											{1, 1, 0, 1},
											{1, 1, 1, 0} };
			std::vector<std::vector<int>> weight = { {0, 1, 1, 1},
													{2, 0, 2, 2},
													{3, 3, 0, 3},
													{3, 3, 3, 0} };
			vector<int> minV = findMinDistance(v, length, weight);
			copy(minV.begin(), minV.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "0 1 2 3 ");
		}
		THEN("OUTPUT is also empty")
		{
			vector<int> v = { 0, 1, 2, 3 };
			std::vector<std::vector<int>> length = { {0, 1, 2, 3},
													{5, 0, 8, 13},
													{21, 34, 0, 55},
													{89, 144, 233, 0} };
			std::vector<std::vector<int>> weight = { {0, 1, 1, 1},
													 {1, 0, 1, 1},
													 {1, 1, 0, 1},
													 {1, 1, 1, 0} };
			vector<int> minV = findMinDistance(v, length, weight);
			copy(minV.begin(), minV.end(), ostream_iterator<int>(output, " "));
			REQUIRE(output.str() == "0 1 2 3 ");
		}
	}
};