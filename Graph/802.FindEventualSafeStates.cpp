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
        {1,0},
        {2,1},
        {3,1},
        {3,7},
        {4,3},
        {5,3},
        {6,3}
    };

    Solution sl;

    for(auto it: sl.eventualSafeNodes(graph))
        std::cout << it << ",";
}