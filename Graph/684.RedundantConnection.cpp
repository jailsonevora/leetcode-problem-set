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
    vector<vector<int>> adjMatrix;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjMatrix.resize(N);
 
        // add edges to the undirected graph
        if(!edges.empty()){
            for (auto &edge: edges)
            {
                adjMatrix[edge.src].push_back(edge.dest);
                //adjList[edge.dest].push_back(edge.src);
            }
        }
    }
};

class Solution {

    bool _dfs(int v, int destination, vector<vector<int>>& graph, vector<int>& discovered){

        if(v == destination)
            return true;

        discovered[v] = 1;
        for(auto& u: graph[v])
            if(!discovered[u])
                if(_dfs(u, destination, graph, discovered))
                    return true;
        return false; 
    }

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
    vector<int> findRedundantConnection_DSU(vector<vector<int>>& edges) {
        
        int n = edges.size()+1;
        vector<pair<int,int>> graph;

        for(auto& edge : edges)
            graph.push_back({edge[0], edge[1]});

        // initialize leads
        vector<int> parent(n, 0), ans;
        for (int i = 0; i < n; ++i) 
            parent[i] = i;  

        for(auto& node: graph){
            int absParentFrom = _find(node.first, parent);
            int absParentTo = _find(node.second, parent);

            if(absParentFrom == absParentTo)
                ans.push_back(node.first), ans.push_back(node.second);

            _union(absParentFrom,absParentTo, parent);
        }        
        return ans; 
    }
    vector<int> findRedundantConnection_DFS(vector<vector<int>>& edges) {
        
        int n = edges.size()+1;
        vector<vector<int>> graph(n);

        vector<int> discovered(n, 0), ans;
        
        for(auto& edge : edges){
            if (!graph[edge[0]].empty() 
                && !graph[edge[1]].empty() 
                && _dfs(edge[0], edge[1], graph, discovered)
                )
                    return edge;
            graph[edge[0]].push_back(edge[1]),
            graph[edge[1]].push_back(edge[0]);
        }

        return {}; 
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
    //     {1,2},
    //     {1,3},
    //     {2,3}
    // };

    vector<vector<int>> adjList = { 
        {1,2},
        {2,3},
        {3,4},
        {1,4},
        {1,5}
    };
    
    Solution sl;
    for(auto it: sl.findRedundantConnection_DFS(adjList))
        cout << it << "\n";
}