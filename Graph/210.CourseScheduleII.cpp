#include <iostream>
#include <stack>
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
            //adjList[edge.dest].push_back(edge.src);
        }
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}
    };

    // vector<Edge> edges = {
    //     {1,0},{0,1}
    // };

    // vector<Edge> edges = {
    //     {0,1},{3,1},{1,3},{3,2}
    // };
 
    // total number of nodes in the graph
    // number of node + zero index in c++
    int N = 4;
 
    // build a graph from the given edges
    Graph graph(edges, N);
    
    Solution sl;
    std::cout << sl.canFinish(N, graph.adjList);
}