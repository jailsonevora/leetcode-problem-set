#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    void bfs(vector<int> graph[], int flowertypes, int u, vector<int>& ans){

        vector<int> visited(flowertypes,0);

        for(auto v: graph[u])
            visited[ans[v]] = 1;
        
        for (int i = 4; i > 0; i--)
            if(!visited[i])
                ans[u] = i;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> graph[n];
        vector<int> ans(n);

        for(auto edge: paths)
            graph[edge[0] - 1].push_back(edge[1] - 1),
                graph[edge[1] - 1].push_back(edge[0] - 1);

        for (int u = 0; u < n; u++)
            bfs(graph, 4+1, u, ans);

        return ans;
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> paths = { 
        {1,2},
        {2,3},
        {3,1}
    };
    int n = 3;

    Solution sl;
    for (auto it : sl.gardenNoAdj(n, paths))
        cout << it;
}