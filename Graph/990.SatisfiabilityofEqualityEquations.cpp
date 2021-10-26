#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int main()
{
    // adjacency edges
    vector<string> equations = { 
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int n = 4, distanceThreshold = 4;

    Solution sl;
    std::cout << sl.findTheCity(n, edges, distanceThreshold);
}