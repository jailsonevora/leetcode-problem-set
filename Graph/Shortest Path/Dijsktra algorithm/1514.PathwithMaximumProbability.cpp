#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //using BFS + AdjList + PriorityQueue as MAXHeap in O(E logV)
    double dijkstra(vector<pair<int, double>> graph[], int start, int end, int n){

        //binary Max heap compared as less than
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int> >> priorityQueue;
        
        //disctance vector
        vector<double> probability(n, 0.0);
        probability[start] = 1.0;

        priorityQueue.push({ 1.0, start});

        //normal level traversal
        while (!priorityQueue.empty())
        {
            int u = priorityQueue.top().second;
            priorityQueue.pop();

            if(u == end)
                break;

            //traverse neighbours
            for(auto it: graph[u]){

                int v = it.first;
                double w = it.second;

                if (probability[v] < probability[u] * w)
                        probability[v] = probability[u] * w,
                        priorityQueue.push({probability[v], v});
            }
        }
        
        return probability[end];

    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // // adjacency lsit
        vector<pair<int, double>> graph[n];

        for (int i = 0; i < edges.size(); i++)
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