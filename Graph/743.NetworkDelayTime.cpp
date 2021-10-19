#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    // using dfs
    void dfs(int u, vector<pair<int,int>> graph[], vector<int>& visitedTime, int time){

        if(visitedTime[u] <= time)
            return;

        visitedTime[u] = time;
        for(auto it: graph[u])
            dfs(it.first,graph, visitedTime, time + it.second);
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // adj list graph
        vector<pair<int,int>> graph[n+1];
        vector<int> visitedTime(n+1,INT_MAX);

        for(auto edge: times)
            graph[edge[0]].push_back({edge[1],edge[2]});

        dfs(k, graph, visitedTime, 0);

        int ans = 0;
        for (int a = 1; a <= n; a++) 
            ans = max(ans, visitedTime[a]);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> times = { 
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n = 4, k = 2;
    
    Solution sl;
    cout << sl.networkDelayTime(times, n, k);
}