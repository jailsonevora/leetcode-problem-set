#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
    //solution 1
    //using bfs + adjList + MinHeap in O(E logV) with pair
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst, int k){

        //pair{Price sum + pair{u + hop}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> priorityQueue;

        //pair{price + hop}
        vector<pair<int,int>> distance(n+1,{INT_MAX,0});
        distance[src].first = 0;
        distance[src].second = 0;

        priorityQueue.push({0,{src,0}});

        while(!priorityQueue.empty()){

            int cost = priorityQueue.top().first;
            int u = priorityQueue.top().second.first;
            int hop = priorityQueue.top().second.second;
            priorityQueue.pop();

            if(u == dst) 
                return cost;
            
            if(distance[u].first < hop) 
                continue;
            
            distance[u].first = hop;
            
            if(hop > k) 
                continue;

            for(auto it: graph[u]){

                int v = it.first;
                int price = it.second;
                priorityQueue.push({cost+price,{v,hop+1}});
            }
        }
        return -1;
    }

    //solution 2
    //using bfs + adjList + MinHeap in O(E logV) with vector<>
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst, int k){

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > priorityQueue;
        priorityQueue.push({0,src,0});
        
        vector<int> dist(n+1, INT_MAX);

        while(!priorityQueue.empty()){
            
            auto tupl = priorityQueue.top(); 
            priorityQueue.pop();
            int cost = tupl[0];
            int u = tupl[1];
            int hop = tupl[2];

            if(u==dst) 
                return cost;
            
            if(dist[u]<hop) 
                continue;
            
            dist[u]=hop;
            
            if(hop > k) 
                continue;

            for(auto it: graph[u]){
                int v = it.first;
                int price = it.second;
                priorityQueue.push({cost+price,v,hop+1});
            }
        }
        return -1;
    }
    
    //using bfs + queue
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst, int k){

        //pair{Price sum + pair{u + hop}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> priorityQueue;

        //pair{price + hop}
        vector<pair<int,int>> cost(n,{INT_MAX,0});
        cost[src].first = 0;
        cost[src].second = 0;

        priorityQueue.push({0,{src,0}});

        while(!priorityQueue.empty()){

            int u = priorityQueue.top().second.first;
            int hop = priorityQueue.top().second.second;
            priorityQueue.pop();

            for(auto it: graph[u]){

                int v = it.first;
                int price = it.second;

                if(cost[v].first > cost[u].first + price && hop <= k){
                    cost[v].first = cost[u].first + price;
                    cost[v].second = cost[u].second + hop;
                    priorityQueue.push({cost[v].first,{v,hop+1}});
                }
            }
        }
        return (cost[dst].first == INT_MAX) ? -1 : cost[dst].first;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        //pair{to + price}
        vector<pair<int, int>> graph[n];

        for(auto flight: flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        return dijkstra(n, graph, src, dst, k);
    }
};

int main(){

    // vector<vector<int>> flights {
    //     {0,1,100},
    //     {1,2,100},
    //     {0,2,500}
    // };

    // int n = 3, src = 0, dst = 2, k = 0;

    vector<vector<int>> flights {
        {0,1,1},
        {0,2,5},
        {1,2,1},
        {2,3,1}
    };

    int n = 4, src = 0, dst = 3, k = 1;
    
    Solution sl;
    cout << sl.findCheapestPrice(n,flights,src,dst,k);
}