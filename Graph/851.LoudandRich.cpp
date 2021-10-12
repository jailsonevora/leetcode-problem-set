#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// //with adjacency list
class Solution {
    // faster
    void _dfsVoid(int u, vector<int> graph[], vector<int>& ans, vector<int>& quiet){
        
        if (ans[u] >= 0)
            return;
        
        ans[u] = u;
        for(auto v: graph[u]){
            _dfsVoid(v, graph, ans, quiet);
            if (quiet[ans[v]] < quiet[ans[u]])             
                ans[u] = ans[v];
        }
    }
    int _dfs(int u, vector<int> graph[], vector<int>& ans, vector<int> quiet){
        
        if (ans[u] >= 0)
            return ans[u];
        
        ans[u] = u;
        for(auto v: graph[u])
            if (quiet[_dfs(v, graph, ans, quiet)] < quiet[ans[u]])             
                ans[u] = ans[v];
        return ans[u];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        vector<int> graph[quiet.size()];

        for(auto edge: richer)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int> ans(quiet.size(), -1);

        //for each unvisited node traverse and push to global vector
        for(int node = 0; node < quiet.size(); node++)
            _dfsVoid(node, graph, ans, quiet);
        return ans;
    }
};

//with adjacency matrix
class Solution {
    int _dfs(int u, vector<vector<int>>& graph, vector<int>& ans, vector<int> quiet){
        
        if (ans[u] >= 0)
            return ans[u];
        
        ans[u] = u;
        for(auto v: graph[u])
            if (quiet[_dfs(v, graph, ans, quiet)] < quiet[ans[u]])                
                ans[u] = ans[v];
        return ans[u];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        //with adjacency matrix
        vector<vector<int>> graph(quiet.size());

        for(auto edge: richer)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int> ans(quiet.size(), -1);

        //for each unvisited node traverse and push to global vector
        for(int node = 0; node < quiet.size(); node++)
            _dfs(node, graph, ans, quiet);
        return ans;
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