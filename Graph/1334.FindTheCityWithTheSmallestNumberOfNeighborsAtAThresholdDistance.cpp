#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //
    int selectMinVertex(vector<int>& value,vector<bool>& processed)
    {
        int minimum = INT_MAX;
        int vertex;
        for(int i=0;i<V;++i)
        {
            if(processed[i]==false && value[i]<minimum)
            {
                vertex = i;
                minimum = value[i];
            }
        }
        return vertex;
    }
    //

    //using BFS + ADjList + PriorityQueue as MinHeap
    void dijkstra(vector<pair<int, int>> graph[], int u, int n, int distanceThreshold, vector<pair<int,int>>& ans){
        
        // use priority queue as min heap
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > pq;
        
        // distance vector
        vector<int> distance(n+1, INT_MAX);

        pq.push(make_pair(0, u));
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
                        pq.push(make_pair(distance[v], v));
            }
        }

        int count = 0;
        for(int node=0; node < n; ++node)
            if(node != u && distance[node] <= distanceThreshold)
                count++;    
        ans.push_back({count,u});
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // adjacencylist graph
        vector<pair<int,int>> graph[n];
        vector<pair<int,int>> ans;

        for(auto edge: edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];   
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        // for each vertice
        for(int u=0; u < n; ++u)
            dijkstra(graph, u, n, distanceThreshold, ans);
    
        //anonnymous class
        sort(ans.begin(),ans.end(),[](const pair<int,int> p1 ,const pair<int,int> p2){
            if(p1.first != p2.first)
                return p1.first < p2.first;
            return p1.second > p2.second;
        });
        return ans[0].second;
    }
};

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