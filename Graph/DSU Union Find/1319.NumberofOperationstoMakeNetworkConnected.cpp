#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Util\Include\Graph.h"

using namespace std;


// adjacent array
// class Solution {
    
//     // find
//     int _find(int v, vector<int>& parent){

//         if(v == parent[v])
//             return v;
//         return parent[v] = _find(parent[v], parent);
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
        
//         int size = connections.size();
//         if( (n - size) > 1)
//             return -1;

//         int ans = 0;

//         vector<int> parent(n, 0);
//         for (int i = 0; i < n; i++)
//             parent[i] = i;

//         for(auto node: connections){
//             int absPFrom = _find(node[0], parent);
//             int absPTo = _find(node[1], parent);

//             if(absPFrom != absPTo)
//                 ans++,
//                 parent[absPTo] = absPFrom;
//         }
//         return n - 1 - ans;
//     }
// };

// union find by rank path compression upgrade and dfs
class Solution {
    
    // find path compression
    int _find(int v, vector<int>& parent){

        if(v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent); // path compression
    }

    // union by rank
    void _union(int from, int to, vector<int>& parent, vector<int>& rank){
        
        if(rank[to] < rank[from])
            parent[to] = from;
        else if(rank[from] < rank[to])
            parent[from] = to;
        else
        {
            parent[to] = from;
            rank[from]++;
        }
    }

    // deph first search
    void _dfs(int u, vector<int> graph[], vector<int>& visited){

        visited[u] = 1;
        for(auto& v: graph[u])
            if(!visited[v])
                _dfs(v, graph, visited);        
    }

public:
    // for DFS to find components or the number of cluster in graph
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int size = connections.size();
        if( (n - size) > 1)
            return -1;

        int ans = 0;

        //adjacentlist
        vector<int> graph[n];

        // making undirected graph
        for(auto& edge: connections)
            graph[edge[0]].push_back(edge[1]),
                graph[edge[1]].push_back(edge[0]);
        
        vector<int> visited(n,0);

        for(int node = 0; node < n; node++)
            if(!visited[node])
                _dfs(node, graph, visited), 
                    ans++;

        return ans - 1;
    }

    // for disjointset Union find by rank with path compression
    // int makeConnected(int n, vector<vector<int>>& connections) {
        
    //     int size = connections.size();
    //     if( (n - size) > 1)
    //         return -1;

    //     int ans = 0;
    //     vector<pair<int,int>> graph;

    //     for(auto& edge: connections)
    //         graph.push_back({edge[0], edge[1]});

    //     // initialize leads
    //     vector<int> parent(n, 0);
    //     vector<int> rank(n, 0);

    //     // intantiate the rankings and parents
    //     for (int i = 0; i < n; i++)
    //         parent[i] = i, 
    //             rank[i] = 0;

    //     for(auto node: graph){
    //         int absPFrom = _find(node.first, parent);
    //         int absPTo = _find(node.second, parent);

    //         if(absPFrom != absPTo)
    //             ans++,
    //             _union(absPFrom, absPTo, parent, rank);
    //     }
    //     return n - 1 - ans;
    // }
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
    //     {0,2},
    //     {1,2},
    // };
    // int n = 4;

    // vector<vector<int>> edges = { 
    //     {0,1},
    //     {0,2},
    //     {0,3},
    //     {1,2},
    //     {1,3}
    // };
    // int n = 6;

    // vector<vector<int>> edges = { 
    //     {0,1},
    //     {0,2},
    //     {0,3},
    //     {1,2}
    // };
    // int n = 6;

    //edge as adjMatrix
    vector<vector<int>> edges = { 
        {1,5},
        {1,7},
        {1,2},
        {1,4},
        {3,7},
        {4,7},
        {3,5},
        {0,6},
        {0,1},
        {0,4},
        {2,6},
        {0,3},
        {0,2}
    };
    int n = 12;
    
    Solution sl;
    cout << sl.makeConnected(n, edges) << "\n";
}