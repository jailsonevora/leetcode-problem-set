#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>

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
                adjList[edge.dest].push_back(edge.src);
            }
        }
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n <= 1)
            return n == 0 ? vector<int>{} : vector<int>{0};
        
        vector<int> indegree(n, 0);
        int min_degree = INT_MAX;
        
        // create a graph
        vector<vector<int>> graph(n);
        for(auto &edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
            ++indegree[edge[0]], ++indegree[edge[1]];
        }
        
        vector<int> result;
        queue<int> queue;
        unordered_set<int> visited;
        
        // add leaf nodes(indegree 1)
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                queue.emplace(i);
                visited.emplace(i);
            }
        }
        
        int n_nodes = queue.size();
        
        // we return the nodes in the last level
        while(!queue.empty()) {
            auto curr = queue.front();
            queue.pop();
            --n_nodes;
            // add node of current level
            result.emplace_back(curr);
            
            // remove the connection count for each neighbor
            for(auto v: graph[curr]) {
                if(!visited.count(v)) {
                    --indegree[v];
                    // it has become a leaf node, add and mark visited
                    if(indegree[v] == 1) {
                        queue.emplace(v);
                        visited.emplace(v);
                    }
                }
            }
            
            // end of level
            if(n_nodes == 0) {
                // not the last level
                if(!queue.empty())
                    result.clear();
                n_nodes = queue.size();
            }
        }
        
        return result;
    }
};


int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {1,0},{1,2},{1,3}
    // };
    // int N = 4;

    vector<vector<int>> edges = {
         {3,0},{3,1},{3,2},{3,4},{5,4}
    };
    int N = 6;

    // vector<Edge> edges = {        
    // };
    // int N = 1;

    // vector<vector<int>> edges = {
    //     {0, 1}        
    // };
    // int N = 2;
 
    // build a graph from the given edges
    //Graph graph(edges, N);
    
    Solution sl;
    for(auto v: sl.findMinHeightTrees(N, edges))
        cout << v << "\n";
}