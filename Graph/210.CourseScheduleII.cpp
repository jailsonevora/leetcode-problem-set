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

class Solution {
    // recursive
    bool dfs(int v, vector<vector<int>>& graph, vector<int> &discovered){

        if(discovered[v] == 1) // viseted
            return false;
        if(discovered[v] == 2) // processing
            return true;
        
        // mark the current node as processing
        discovered[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, discovered))
                return true;
        
        discovered[v] = 1; // viseted
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //to convert edge list to adjacent list
        //vector<vector<int>> graph(numCourses);
        /*for (auto &edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);*/
        
        vector<int> discovered(numCourses, 0);

        for(int node = 0; node < numCourses; node++)
            if (!discovered[node])
                if(dfs(node, prerequisites, discovered))
                        return false;
        return true;
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