#include <iostream>
#include <vector>
#include "../lw1.2/MaxCostBag.h"

using namespace std;

bool NextSet(vector<int>& a, int n, int m)
{
    int k = m;
    for (int i = k - 1; i >= 0; --i)
        if (a[i] < n - k + i + 1)
        {
            ++a[i];
            for (int j = i + 1; j < k; ++j)
                a[j] = a[j - 1] + 1;
            return true;
        }
    return false;
}

vector<int> MaxCostBag(const vector<vector<int>>& costMatrix, int weightLimit)
{
    if (costMatrix.size() < 1)
    {
        return {};
    };
    for (int i = 0; i < costMatrix.size(); i++) 
    {
        if (costMatrix[i].size() < 3)
        {
            return {};
        };
    }
    vector<int> order = {};
    for (int i = 0; i < costMatrix.size(); i++)
    {
            order.push_back(costMatrix[i][0]);
    };
    int n = order.size();
    int maxC = 0;
    vector<int> solution = {};
    int answSize = 0;
    for (int m = 1; m <= n; m++)
    {
        vector<int> copyOrder = order;
        do
        {
            if (n >= m)
            {
                int weight = 0;
                int cost = 0;
                for (int i = 0; i < m; i++)
                {
                    weight += costMatrix[copyOrder[i] - 1][1];
                    cost += costMatrix[copyOrder[i] - 1][2];
                }
                if ((weight <= weightLimit) && (maxC < cost))
                {
                    maxC = cost;
                    solution = copyOrder;
                    answSize = m;
                }
            }
            else
            {
                break;
            }
        } while (NextSet(copyOrder, n, m));
    }
    vector<int> answer = {};
    for (int i = 0; i < answSize; i++)
    {
        answer.push_back(solution[i]);
    }
    return answer;
}