#include <iostream>
#include <queue>
#include <vector>

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
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

class Solution {
    bool bfs(int n, vector<vector<int>>& edges, int start, int end, vector<bool> &discovered){

        queue<int> queue;

        discovered[start] = true;

        queue.push(start);

        while (!queue.empty())
        {
            start = queue.front();
            queue.pop();

            for (int u: edges[start])
                if (!discovered[u])
                {
                    discovered[u] = true;
                    queue.push(u);
                    if (u == end)
                        return true;
                }
        }
        return false;
    }
public:
    //bfs
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        // to keep track of whether a vertex is discovered or not
        vector<bool> discovered(n, false);
        
        return bfs(n, edges, start, end, discovered);
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {0, 1}, {1, 2}, {2, 0}
    // };

    vector<Edge> edges = {
        {0,1},{0,2},{3,5},{5,4},{4,3}
    };
 
    // total number of nodes in the graph
    // number of node + zero index in c++
    int N = 6;
 
    // build a graph from the given edges
    Graph graph(edges, N);
    
    Solution sl;
    std::cout << sl.validPath(N, graph.adjList, 0, 5);
}