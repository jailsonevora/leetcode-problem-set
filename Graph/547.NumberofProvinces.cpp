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

class SolutionDSU {
        
    int _find(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = _find(parent[v]);
    }
    
    void _union(int from, int to, vector<int>& parent) {
        from = _find(from);
        to = _find(to);
        if (from != to)
            parent[to] = from;
    }
public:
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int i, j, province = 0, n = M.size();
        
        // initialize leads for every kid as themselves
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;  
          
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(M[i][j])
                    _union(i, j);
        
        for(i = 0; i < n; i++)
            if(i == parent[i])
                province++;
        
        return province;
    }
};

class Solution {
    void DFS(vector<vector<int>> &grid, int v, vector<int>& visited){
               
        for (int u = 0; u < grid.size(); u++)
            if(grid[v][u] == 1 && visited[u] == 0){
                visited[u] = 1;
                DFS(grid, u, visited);
            }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int province = 0;
        vector<int> visited(isConnected.size(), 0);
        
        for(int row = 0; row < isConnected.size(); row++)
            if(visited[row] == 0)
                DFS(isConnected, row, visited), 
                    province++;
        return province;        
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

    vector<vector<int>> grid = { 
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    // vector<vector<int>> grid = { 
    //     {1,0,0},
    //     {0,1,0},
    //     {0,0,1}
    // };
    
    Solution sl;
    std::cout << sl.findCircleNum(grid);
}