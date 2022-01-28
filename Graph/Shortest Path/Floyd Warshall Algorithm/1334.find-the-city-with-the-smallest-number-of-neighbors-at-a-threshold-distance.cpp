/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //Floyd Warshall Algorithm
    int floyd_Warshall(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dis(n, vector<int>(n, 10001));
        int res = 0, smallest = n;

        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];

        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
            
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // adjacencyList graph
        //vector<pair<int,int>> graph[n];

        // adjacencyMatrix graph
        vector<vector<int>> graph(n, vector<int>(n,0));

        vector<pair<int,int>> ans;

        //adjList
        // for(auto edge: edges)
        // {
        //     int u = edge[0], v = edge[1], w = edge[2];   
        //     graph[u].push_back({v,w});
        //     graph[v].push_back({u,w});
        // }

        //adjMatrix
        for(auto edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u][v] = w;
            graph[v][u] = w;
        }

        // Floyd Warshall Algorithm 
    
        //anonymous class/method
        sort(ans.begin(),ans.end(),[](const pair<int,int> p1 ,const pair<int,int> p2){
            if(p1.first != p2.first)
                return p1.first < p2.first;
            return p1.second > p2.second;
        });
        return ans[0].second;
    }
};
// @lc code=end
int main()
{
    // adjacency edges
    vector<vector<int>> edges = { 
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int n = 4, distanceThreshold = 4;

    Solution sl;
    std::cout << sl.findTheCity(n, edges, distanceThreshold);
}
