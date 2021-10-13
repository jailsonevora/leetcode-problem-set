#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // recursive check cycle for a path
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
    void _dfs(int u, vector<vector<int>>& graph, vector<int> &discovered, stack<int> &ans){

        discovered[u] = 1;
        for (int v : graph[u])
            if (!discovered[v])
                _dfs(v, graph, discovered, ans);
        ans.push(u);
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> visited(graph.size(), 0), ans;

        for (int node = 0; node < graph.size(); node++)
            if(!visited[node])
                if
        
        
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