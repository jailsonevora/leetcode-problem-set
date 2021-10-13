#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // recursive check cycle
    bool dfs(int v, vector<vector<int>>& graph, vector<int> &discovered){

        if(discovered[v] == 1) // viseted
            return false;
        if(discovered[v] == 2) // processing
            return true;
        
        // mark the current node as processing
        discovered[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, discovered))
                return true;
        
        discovered[v] = 1; // viseted
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> visited(graph.size(), 0);
        
    }
};

int main()
{

    // adjacency matrix
    vector<vector<int>> graph = { 
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    // adjacency matrix
    // vector<vector<int>> graph = { 
    //     {1,2,3,4},
    //     {1,2},
    //     {3,4},
    //     {0,4},
    //     {}
    // };

    Solution sl;

    for(auto it: sl.eventualSafeNodes(graph))
        std::cout << it << ",";
}