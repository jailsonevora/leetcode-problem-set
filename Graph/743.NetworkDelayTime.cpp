#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    void dfs(int u, vector<pair<int,int>> graph[], vector<int>& visited, int& t){

        visited[u] = 1;
        for(auto it: graph[u]){
            if(!visited[it.first])
                dfs(it.first,graph, visited, t);
            int tp = max(t,it.second);
            t = 
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // adj list graph
        vector<pair<int,int>> graph[n+1];
        vector<int> visitedTime(n+1,INT_MAX);

        for(auto edge: times)
            graph[edge[0]].push_back({edge[1],edge[2]});

        int t = 0;
        if(!visited[k])
            dfs(k, graph, visited, t);
        

        return t;

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