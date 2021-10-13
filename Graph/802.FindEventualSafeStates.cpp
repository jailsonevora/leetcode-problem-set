#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // recursive check cycle for a path
    bool dfs(int v, vector<vector<int>>& graph, vector<int> &visited){

        if(visited[v] == 1) // viseted
            return false;
        if(visited[v] == 2) // processing
            return true;
        
        // mark the current node as processing
        visited[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, visited))
                return true;
        
        visited[v] = 1; // viseted
        return false;
    }
    void _dfs(int u, vector<vector<int>>& graph, vector<int> &visited, vector<int> &ans){

        visited[u] = 1;
        for (int v : graph[u])
            if (!visited[v])
                _dfs(v, graph, visited, ans);
        ans[u]=u;
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