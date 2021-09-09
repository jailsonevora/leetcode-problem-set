#include <iostream>
#include <queue>
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
                //adjList[edge.dest].push_back(edge.src);
            }
        }
    }
};

class Solution {
    // void _dfs(int u, vector<vector<int>>& graph, int& min, int ans = 1){

    //     for (int v : graph[u])
    //         _dfs(v, graph, min, ans+1);
    //     ans = std::min(ans, min);
    // }
    int _bfs(int u, vector<vector<int>>& graph){

        queue<int> queue;
        int ans;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int node = queue.front();
                queue.pop();

                for(auto child: graph[node])
                    queue.push(child);                
            }
            ans++;            
        }
        return ans;        
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        //to convert edge list to adjacent list
        vector<vector<int>> graph(n);
        for (auto &edge: edges)
            graph[edge[0]].push_back(edge[1]);

        int min = INT_MAX;
        vector<int> tmp(n);

        //for each unvisited node traverse and push to global stack
        for(int node = 0; node < n; node++)
        {
            int ans = bfs(node, graph);
            if(ans <= min){
                min = ans;
                tmp.insert(node,ans);
            }
            for(int i=0; i < tmp.size(); ++i)
                if(tmp[i] >= ans)
                    tmp[i] = INT_MAX;
        }
        vector<int> result;
        for(int i=0; i < tmp.size(); ++i)
            if(tmp[i] != INT_MAX)
                result.push_back(i);

        return result;
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

    vector<Edge> edges = {
        
    };
    int N = 1;
 
    // build a graph from the given edges
    Graph graph(edges, N);
    
    Solution sl;
    for(auto v: sl.findMinHeightTrees(N, graph.adjList))
        cout << v << "\n";
}