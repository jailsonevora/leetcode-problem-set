#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    void bfs(vector<int> graph[], int n, int u){

        // bfs
        queue<int> queue;
        vector<int> visited(n,0);

        queue.push(u);
        visited[u] = 1;

        while (!queue.empty())
        {
            
        }
        
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> graph[n];

        for(auto edge: paths)
            graph[edge[0]].push_back(edge[1]),
                graph[edge[0]].push_back(edge[1]);

        for (int u = 1; u < n; u++)
            bfs(graph, n, u);
        

        
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