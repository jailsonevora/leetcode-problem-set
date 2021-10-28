#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    double dijkstra(vector<pair<int, double>> graph[], int start, int end, int n){

        //binary heap
        priority_queue<pair<int, double>, vector<pair<int, double>>, less<pair<int, double> >> priorityQueue;

        //disctance vector
        vector<double> distance(n, 0.0);
        distance[start] = 1.0;

        priorityQueue.push({start,1.0});

        //normal level traversal
        while (!priorityQueue.empty())
        {
            int u = priorityQueue.top().first;
            priorityQueue.pop();

            if(u == end)
                break;

            //traverse neighbours
            for(auto it: graph[u]){

                int v = it.first;
                int w = it.second;

                if (distance[v] < distance[u] * w)
                    distance[v] = distance[u] * w,
                        priorityQueue.push({v,distance[v]});
            }
        }
        
        return distance[end];

    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // adjacency lsit
        vector<pair<int, double>> graph[n];

        for (int i = 0; i < n; i++)
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]}),
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});

        return dijkstra(graph, start, end, n);
        
        
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> edges = { 
        {0,1},
        {1,2},
        {0,2}
    };
    //weight or probability
    vector<double> succProb = { 
        0.5,
        0.5,
        0.2
    };
    int n = 3;

    // adjacency edges
    // vector<vector<int>> edges = { 
    //     {0,1},
    //     {1,2},
    //     {0,2}
    // };
    // //weight or probability
    // vector<double> succProb = { 
    //     0.5,
    //     0.5,
    //     0.3
    // };
    // int n = 3;

    // adjacency edges
    // vector<vector<int>> edges = { 
    //     {0,1}
    // };
    // //weight or probability
    // vector<double> succProb = { 
    //     0.5
    // };
    // int n = 3;


    Solution sl;
    std::cout << sl.maxProbability(n, edges, succProb, 0,2);
}