#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// A class to represent a graph object
class Graph {
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        if(!edges.empty()){
            for (auto &edge: edges)
            {
                adjList[edge.src].push_back(edge.dest);
                //adjList[edge.dest].push_back(edge.src);
            }
        }
    }
};

class Solution {
    int _find(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent);
    }

    void _union(int from, int to, vector<int>& parent) {
        from = _find(from, parent);
        to = _find(to, parent);
        if (from != to)
            parent[to] = from;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(edges.size());

        for(auto edge : edges)
            graph[edge[0]].push_back(edge[1]),
            graph[edge[1]].push_back(edge[0]);

        // initialize leads
        vector<int> parent(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) 
            parent[i] = i;

        return vector<int>{}; 
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

    vector<vector<int>> adjList = { 
        {1,2},
        {1,3},
        {2,3}
    };
    
    Solution sl;
    for(auto it: sl.findRedundantConnection(adjList))
        cout << it << "\n";
}