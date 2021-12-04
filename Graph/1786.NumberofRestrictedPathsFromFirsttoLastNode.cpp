#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    // using dfs + Dynaminc programing
    int dfs(int n, vector<pair<int, int>> graph[], vector<int>& distance, vector<int>& dp, const int mod = 1e9 + 7){
        
        if(n == 1) 
            return 1;
        
        if(dp[n] != -1) 
            return dp[n];

        int paths = 0;

        for(auto it: graph[n]){
            if(distance[it.first] > distance[n]){
                paths += (dfs(it.first, graph, distance, dp, mod) % mod) % mod;
            }
        }

        return dp[n] = paths%mod;
    }
    // Run a Dijkstra from node numbered n to compute distance from the last node.
    // using dijkstra shortest path with adjLis + minHeap O(e logv)
    void dijkstra(vector<pair<int, int>> graph[], int n, vector<int>& distance){

        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<> > p_queue;
        p_queue.push({0,n});

        while (!p_queue.empty())
        {
            int u = p_queue.top().second;
            int dis = p_queue.top().first;
            p_queue.pop();

            for(auto it: graph[u]){
                
                int v = it.first;
                int w = it.second;

                if(distance[v] > dis + w)
                    distance[v] = dis + w,
                        p_queue.push({distance[v], v});
            }
        }
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> graph[n+1];
        vector<int> distance(n+1, INT_MAX);

        for(auto edge: edges)
            graph[edge[0]].push_back({edge[1],edge[2]}),
                graph[edge[1]].push_back({edge[0],edge[2]});

        // 1st step to calculate shortestpath from node n to last node
        dijkstra(graph, n, distance);

        // 2nd Now this problem reduces to computing the number of paths from 1 to n in a DAG, a standard DP problem.
        vector<int> dp(n+1,-1);
        return dfs(n, graph, distance, dp, 1e9 + 7);
    }
};

int main(){

    //ex1
    vector<vector<int>> edges = {
        {1,2,3},
        {1,3,3},
        {2,3,1},
        {1,4,2},
        {5,2,2},
        {3,5,1},
        {5,4,10}
    };
    int n = 5;

    //ex2
    // vector<vector<int>> edges = {
    //     {1,3,1},
    //     {4,1,2},
    //     {7,3,4},
    //     {2,5,3},
    //     {5,6,1},
    //     {6,7,2},
    //     {7,5,3},
    //     {2,6,4}
    // };
    // int n = 7;

    Solution sl;
    cout << sl.countRestrictedPaths(n, edges);
}
