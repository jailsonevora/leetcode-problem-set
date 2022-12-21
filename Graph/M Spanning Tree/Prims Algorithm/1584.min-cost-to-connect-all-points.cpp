/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<numeric>

using namespace std;

class Solution {
    int manhattanDist(vector<int> &x, vector<int> &y){
        return (abs(x[0]-y[0]) + abs(x[1]-y[1]));
    }
public:
    //Minimun Spanning Tree using BFS + adjList + MinHeap in O(E log V)
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<pair<int,int>> graph[n];

        for(int r=0; r<n; r++){
            for(int c=r+1; c<n; c++){
                int dist = manhattanDist(points[r],points[c]);
                graph[r].push_back({c,dist});
                graph[c].push_back({r,dist});
            }
        }

        // binary heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> priorityQueue;
        
        vector<int> distance(n, INT_MAX); //Keeps shortest path values to each vertex from source
        vector<int> parent(n,-1); //Stores Shortest Path Structure
        vector<bool> visited(n, false);
        
        // {cost,node}
        priorityQueue.push({0,0});
        distance[0] = 0;

        while (!priorityQueue.empty())
        {   
            int u = priorityQueue.top().second;
            int costU = priorityQueue.top().first;
            priorityQueue.pop();
            
            visited[u] = true;

            // {node,cost}
            for(auto it: graph[u]){
                int v = it.first;
                int costV = it.second;

                // the main difference between Prims vs dijkstra
                // Prims MST distance[v] > costV
                // Dijkstra SSSP distance[v] > costV + distance[u]
                if(!visited[v] && distance[v] > costV){
                    distance[v] = costV;
                    priorityQueue.push({distance[v],v});
                    parent[v] = u;
                }              
            }
        }
        //Print MSP Tree Path Graph
        for(int i=1; i<n; ++i)
            cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<distance[i]<<"\n";
        return accumulate(distance.begin(),distance.end(),0);
    }
};
// @lc code=end
int main(){

    vector<vector<int>> points = {
        {0,0},
        {2,2},
        {3,10},
        {5,2},
        {7,0}
    };
    // vector<vector<int>> points = {
    //     {3,12},
    //     {-2,5},
    //     {-4,1}
    // };

    Solution sl;
    cout << sl.minCostConnectPoints(points);
}

