#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
    //using bfs + adjList + MinHeap in O(E logV)
    int dijkstra(int n, vector<pair<int,int>> graph[], int src, int dst, int k){

        //pair{Price sum + pair{u + numHop}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> priorityQueue;

        //pair{price + num hop}
        vector<pair<int,int>> distance(n,{0,0});
        distance[src].first = 0;
        distance[src].second = 0;

        priorityQueue.push({0,{src,0}});

        while(!priorityQueue.empty()){

            int u = priorityQueue.top().second.first;
            int numHop = priorityQueue.top().second.second;
            priorityQueue.pop();

            for(auto it: graph[u]){

                int v = it.first;
                int price = it.second;

                if(distance[v].first < distance[u].first + price){
                    distance[v].first = distance[u].first + price;
                    distance[v].second = distance[u].second + numHop;
                    priorityQueue.push({distance[v].first,{v,numHop+1}});
                }
            }
        }




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

    vector<vector<int>> flights {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };

    int n = 3, src = 0, dst = 2, k = 1;

    Solution sl;
    cout << sl.findCheapestPrice(n,flights,src,dst,k);
}