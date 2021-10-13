#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
    }
};

int main()
{

    // adjacency matrix
    vector<vector<int>> graph = { 
    };

    // adjacency matrix
    vector<vector<int>> graph = { 
        {1,2,3,4},
        {1,2},
        {3,4},
        {0,4},
        {}
    };

    Solution sl;

    for(auto it: sl.eventualSafeNodes(graph))
        std::cout << it << ",";
}