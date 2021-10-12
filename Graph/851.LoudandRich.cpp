#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    int8_t _dfs(int u, vector<int> graph[], vector<int>& visited, vector<int>& ans, vector<int> quiet){
        
        if (ans[u] >= 0) {
            return ans[u];
        }
        visited[u] = 1;

        for(auto v: graph[u])
            if(!visited[v])
                if (quiet[_dfs(v, graph, visited, ans, quiet)] > quiet[ans[u]])                
                    ans[v] = ans[u];
        return ans[u];

    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        vector<int> graph[quiet.size()];

        for(auto edge: richer)
            graph[edge[0]].push_back(edge[1]);

        vector<int> visited(quiet.size(), 0);
        vector<int> ans(quiet.size(), -1);

        //for each unvisited node traverse and push to global stack
        for(int node = 0; node < quiet.size(); node++)
            if(!visited[node])
                _dfs(node, graph, visited, ans, quiet);

        // reverse global stack when using dfs recursively
        // vector<int> revereStack;
        // while (!ans.empty())
        //     revereStack.push_back(ans.top()),
        //         ans.pop();

        cout << 1;
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