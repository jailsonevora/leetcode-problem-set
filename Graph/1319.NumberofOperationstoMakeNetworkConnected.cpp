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
    
    // find
    int _find(int v, vector<int>& parent){

        if(v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent);
    }

    // union
    void _union(int from, int to, vector<int>& parent){
        from = _find(from, parent);
        to = _find(to, parent);

        if(from != to)
            parent[to] = from;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n - connections.size() > 1)
            return -1;

        int ans = 0;
        vector<pair<int,int>> graph;

        for(auto& edge: connections)
            graph.push_back({edge[0], edge[1]});

        // initialize leads
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for(auto node: graph){
            int absPFrom = _find(node.first, parent);
            int absPTo = _find(node.second, parent);

            if(absPFrom == absPTo)
                ans++;

            _union(absPFrom, absPTo, parent);
        }
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

    // vector<vector<int>> adjList = { 
    //     {0,1},
    //     {0,2},
    //     {1,2},
    // };
    // int n = 4;

    // vector<vector<int>> adjList = { 
    //     {0,1},
    //     {0,2},
    //     {0,3},
    //     {1,2},
    //     {1,3}
    // };
    // int n = 6;

    vector<vector<int>> adjList = { 
        {0,1},
        {0,2},
        {0,3},
        {1,2}
    };
    int n = 6;
    
    Solution sl;
    cout << sl.makeConnected(n, adjList) << "\n";
}