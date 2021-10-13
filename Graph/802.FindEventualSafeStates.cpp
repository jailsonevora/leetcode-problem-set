#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // check cycle in for each path
    bool hasCycle(int u, vector<vector<int>>& graph, vector<int> &visited){

        if(visited[u] == 1) // viseted
            return false;
        // processing current node
        // if so we have a cycle 
        if(visited[u] == 2) 
            return true;
        
        // mark the current node as processing
        visited[u] = 2;

        // do for every edge `v —> u`
        for (int v: graph[u])
            if(hasCycle(v, graph, visited))
                return true;
        
        visited[u] = 1; // viseted
        return false;
    }

    // check cycle in for each path
    // bool hasCycle(int u, vector<vector<int>>& graph, vector<int> &visited){

    //     if(visited[u] == 1) // processing
    //         return true; 

    //     visited[u] = 1; //visited
    //     // do for every edge `u —> v`
    //     for (int u: graph[u])
    //         if(hasCycle(u, graph, visited))
    //             return true;
    //     visited[u] = 1;
    //     return false;
    // }

    // topological sort;
    void _dfs(int u, vector<vector<int>>& graph, vector<int> &visited, vector<int> &ans){

        visited[u] = 1;
        for (int v : graph[u])
            if (!visited[v])
                _dfs(v, graph, visited, ans);
        ans.push_back(u);
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> visited(graph.size(), 0), ans, discovered(graph.size(), 0);

        for (int node = 0; node < graph.size(); node++)
            if(!visited[node] && !hasCycle(node, graph, discovered))
                _dfs(node, graph, visited, ans);

        sort(ans.begin(), ans.end());
        return ans;        
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