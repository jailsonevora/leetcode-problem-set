#include "Util\Include\Graph.h"

// A class to represent a graph object
class Graph {
public:
    // a vector of vectors to represent an adjacency matrix
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
                adjMatrix[edge.dest].push_back(edge.src);
            }
        }
    }
};
