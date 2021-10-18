#include "Util\Include\Graph.h"

// Graph Constructor
Graph::Graph(vector<Edge> const &edges, int N)
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
