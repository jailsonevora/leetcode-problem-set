#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void _dfs(int u, vector<int> graph[], vector<int>& visited, stack<int>& stack){

        visited[u] = 1;

        for(auto v: graph[u])


    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        vector<int> graph[quiet.size()];

        for(auto edge: richer)
            graph[edge[0]].push_back(edge[1]);

        vector<int> visited(quiet.size(), 0);
        stack<int> ans;

        for(int node = 0; node < quiet.size(); node++)
            if(!visited[node])
                _dfs(node, graph, visited, ans);

        
    }
};

int main()
{

    // adjacency matrix
    // vector<vector<int>> richer = { 
    // };

    // // vector
    // vector<int> quiet = {
    //     0
    // };

    // adjacency matrix
    vector<vector<int>> richer = { 
        {1,0},
        {2,1},
        {3,1},
        {3,7},
        {4,3},
        {5,3},
        {6,3}
    };

    // vector
    vector<int> quiet = {
        3,2,5,4,6,1,7,0
    };

    Solution sl;

    for(auto it: sl.loudAndRich(richer, quiet))
        std::cout << it << ",";
}