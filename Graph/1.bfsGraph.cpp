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


// Perform BFS on the graph starting from vertex `v`
bool BFS(Graph const &graph, int v, vector<bool> &discovered, int N, int vu)
{
    // create a queue for doing BFS
    queue<int> q;
 
    // mark the source vertex as discovered
    discovered[v] = true;
 
    // enqueue source vertex
    q.push(v);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        v = q.front();
        q.pop();
        cout << v << " ";
 
        // do for every edge `v —> u`
        for (int u: graph.adjList[v])
        {
            if (!discovered[v])
            {
                // mark it as discovered and enqueue it
                discovered[v] = true;
                q.push(u);
            }
            vu++;
        }
    }

    if(vu == N-2)
        return true;
    else
        return false;
}

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
    
    
 
    // Perform BFS traversal from all undiscovered nodes to
    // cover all unconnected components of a graph
    for (int i = 0; i < N; i++)
    {
        //bucket
        int vu = 0;
        if (discovered[i] == false)
        {
            // start BFS traversal from vertex `i`
            if(BFS(graph, i, discovered, N, vu))
                break;
        }
    } 
    return 0;
}