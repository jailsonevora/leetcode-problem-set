#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

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
                //adjList[edge.dest].push_back(edge.src);
            }
        }
    }
};

class Solution {
    
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(trust.empty() && n==1)
            return 1;

        //counts outdegree and indegree of a person or node 
		//outdegree means number of nodes that are trusted by given specific node
        //indegree means number of nodes that trusts a given specific node 
        vector<int> count(n + 1, 0);
        for (auto& edge : trust)
            count[edge[0]]--, count[edge[1]]++;
        
        for (int i = 1; i <= n; ++i) 
            if (count[i] == n - 1) 
                return i;
        return -1;
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {1, 0}
    // };
    // int N = 2;

    // vector<Edge> edges = {
    //      {1,0},{2,0},{3,1},{3,2}
    // };
    // int N = 4;

    // vector<Edge> edges = {
        
    // };
    // int N = 1;
 
    // build a graph from the given edges
    //Graph graph(edges, N);

    vector<vector<int>> adjList = { 
        {1,3},{2,3}
    };
    int N = 3;
    
    Solution sl;
    cout << sl.findJudge(N, adjList);
}