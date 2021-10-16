#include<iostream>
#include<vector>
#include "Util\Include\Edge.h"

// A class to represent a graph object
class Graph {
public:
    // a vector of vectors to represent an adjacency matrix
    vector<vector<int>> adjMatrix;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N);
};