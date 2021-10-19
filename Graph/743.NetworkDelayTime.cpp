#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {

    //using BFS + adjList + MinHeap in O(E log V)
    void dijkstra(int u, vector<pair<int,int>> graph[], int n, vector<int>& distance){

        // use priority queue as min heap
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > pq;

        pq.push({0,u});
        distance[u] = 0;

        // normal BFS traversal
        while(!pq.empty()){

            int u = pq.top().second;
            pq.pop();

            // traverse for the neighbors of u
            for(auto it : graph[u]){

                int v = it.first;
                int w = it.second;

                if(distance[v] > distance[u] + w)
                    distance[v] = distance[u] + w,
                        pq.push({distance[v], v});
            }
        }

    }
    // using DFS
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
        for(auto edge: times)
            graph[edge[0]].push_back({edge[1],edge[2]});
        
        // for dfs
        //vector<int> visitedTime(n+1,INT_MAX);
        //dfs(k, graph, visitedTime, 0);
        
        // for dijkstra
        // distance vector for dijkstra
        vector<int> distance(n+1, INT_MAX);
        dijkstra(k, graph, n, distance);


        int ans = 0;
        for (int a = 1; a <= n; a++) 
            ans = max(ans, distance[a]);
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