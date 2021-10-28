#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    double dijkstra(vector<pair<int, int>> graph[], int u, int v, int n){

        //binary heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int> >> priorityQueue;

        //disctance vector
        vector<int> distance(n, INT_MIN);

        priorityQueue.push({u,0});

        //normal level traversal
        while (!priorityQueue.empty())
        {
            int u = priorityQueue.top().first;
            priorityQueue.pop();

            //traverse neighbours

        }
        

    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // adjacency lsit
        vector<pair<int, int>> graph[n];

        for (int i = 0; i < n; i++)
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]}),
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        
        
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