#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
    //using bfs + adjList + MinHeap in O(E logV)
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst){

    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> graph[n];

        for(auto flight: flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        return dijkstra(n, graph,)
        
    }
};

int main(){

    vector<vector<int>> flights {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };

    int n = 3, src = 0, dst = 2, k = 1;

    Solution sl;
    cout << sl.findCheapestPrice(n,flights,src,dst,k);
}