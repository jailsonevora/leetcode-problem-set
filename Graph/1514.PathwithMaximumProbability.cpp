#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int main()
{
    // adjacency edges
    vector<vector<int>> edges = { 
        {0,1},
        {1,2},
        {0,2}
    };
    vector<vector<int>> succProb = { 
        {0,1},
        {1,2},
        {0,2}
    };

    int n = 3;

    Solution sl;
    std::cout << sl.findTheCity(n, edges, distanceThreshold);
}