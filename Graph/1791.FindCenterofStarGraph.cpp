#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;


// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency matrix
    vector<vector<int>> adjMatrix;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjMatrix.resize(N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjMatrix[edge.src].push_back(edge.dest);
            adjMatrix[edge.dest].push_back(edge.src);
        }
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_set<int> node;
        for (auto edge : edges)
        {
            if (node.count(edge[0])) 
                return edge[0];
            if (node.count(edge[1])) 
                return edge[1];
            
            node.insert(edge[0]);
            node.insert(edge[1]);
        }
        
        return -1;
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {4, 2}
        // vertex 0, 13, and 14 are single nodes
    };
 
    // total number of nodes in the graph
    // number of node + zero index in c++
    int N = 5;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N, false);
    
    Solution sl;

    cout << sl.findCenter(graph.adjMatrix);
    
    return 0;
}