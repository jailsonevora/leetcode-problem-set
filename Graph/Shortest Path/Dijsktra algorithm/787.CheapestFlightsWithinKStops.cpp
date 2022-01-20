#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
    //solution 1
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
    
    //solution 2
    //using bfs + queue
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst, int k){

        //pair{price + u}}
        queue<pair<int,int>> queue;
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;

        queue.push({0,src});

        k+=1;
        while(!queue.empty()){

            int size=queue.size();

            k--;
            if(k<0) // break statement
                break;

            for(int i=0;i<size;i++){
                
                int u_price = queue.front().first;
                int u = queue.front().second;
                queue.pop();

                for(auto it: graph[u]){

                    int v = it.first;
                    int v_price = it.second;

                    if(cost[v] > u_price + v_price){
                        cost[v] = u_price + v_price;
                        queue.push({cost[v],v});
                    }
                }
            }
        }
        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
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