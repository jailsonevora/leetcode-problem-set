#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Util\Include\Graph.h"

using namespace std;

class Solution {
    void _dfs(int v, vector<pair<int,int>> graph[], vector<int>& visited, int& ans){

        visited[v] = 1;

        for (auto [u, direction]: graph[v])
            if(!visited[u]){
                _dfs(u, graph, visited, ans);
                if(direction == 1)
                    ans++;
            }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<pair<int,int>> graph[n+1];
        vector<int> visited(n, 0);
        int ans = 0;

        for(auto& edge: connections)
            graph[edge[0]].push_back({edge[1], 1}),
            graph[edge[1]].push_back({edge[0], -1});

        for (int node = 0; node < n; node++)
            if(!visited[node])
                _dfs(node, graph,visited, ans);       
        return ans;        
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {1, 0}
    // };
    // int N = 2;

    // vector<Edge> edges = {
    //      {1,0},{2,0},{3,1},{3,2}
    // };
    // int N = 4;

    // vector<Edge> edges = {
        
    // };
    // int N = 1;
 
    // build a graph from the given edges
    //Graph graph(edges, N);

    // vector<vector<int>> edges = {
    //     {0,1},
    //     {1,3},
    //     {2,3},
    //     {4,0},
    //     {4,5}
    // };
    // int N = 6;

    vector<vector<int>> edges = {
        {1,2},
        {2,0}
    };
    int N = 3;
    
    Solution sl;
    std::cout << sl.minReorder(N, edges);
}