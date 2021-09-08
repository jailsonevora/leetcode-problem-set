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
    bool dfs(int v, vector<vector<int>>& graph, vector<bool> &discovered){

        if(discovered[v] == 1) // viseted
            return false;
        if(discovered[v] == 2) //processed
            return true;
        
        // mark the current node as discovered
        discovered[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, discovered))
                return true;
        
        discovered[v] = 1; //processed
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<vector<int>> graph(numCourses);
        for (auto &edge: prerequisites)
        {
             graph[edge[0]].push_back(edge[1]);
             //graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> discovered(numCourses, 0);

        
        for(int node = 0; node < numCourses; ++node)
            if (discovered[node] == 0)
                if(dfs(node, graph, discovered))
                    return false;
        return true;
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