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
    void DFS(vector<vector<int>> &grid, int x, int y){
               
        grid[x][y] = 2;
        for (int u: grid[x])
            if(grid[x][u] == 1)
                DFS(grid, x, u);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // [1,0,0,1],
        // [0,1,1,0],
        // [0,1,1,1],
        // [1,0,1,1]
        
        int province = 0;
        
        for(int row = 0; row < isConnected.size(); row++)
            for(int col = 0; col < isConnected[0].size(); col++)
                if(isConnected[row][col] == 1)
                    DFS(isConnected, row, col), 
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