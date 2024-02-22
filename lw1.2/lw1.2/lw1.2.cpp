#include <iostream>
#include <vector>
#include "../lw1.2/MaxCostBag.h"

using namespace std;

int main()
{
    vector<vector<int>> objects = { {1, 1, 1},
                                   {2, 2, 2},
                                   {3, 3, 3},
                                   {4, 4, 4} };
    vector<int>inBag = MaxCostBag(objects, 5);
    copy(inBag.begin(), inBag.end(), ostream_iterator<int>(cout, " "));
    return 0;
}