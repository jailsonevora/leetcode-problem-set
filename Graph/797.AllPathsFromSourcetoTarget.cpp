#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Util\Include\Graph.h"

using namespace std;

class Solution {
    void dfs_backtracking(int v, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> vec){
        
        vec.push_back(v);
        
        if(v == graph.size() - 1)
            ans.push_back(vec);
        else{
            for (auto u: graph[v])
                dfs_backtracking(u, graph, ans, vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> vec;

        dfs_backtracking(0, graph, ans, vec);

        return ans;        
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
        {{1,2},{3},{3},{}}
    };
    int N = 4;
    
    Solution sl;
    for(auto v: sl.allPathsSourceTarget(adjList))
        for(auto u: v)
            cout << u << "\n";
}