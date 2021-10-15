#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    // using simple implementation of dijkstra in O(V^2)
    void _dijkstra(int n, vector<vector<int>> graph, int u, int distanceThreshold, vector<pair<int,int>>& ans)
    {
        int parent[n];		//Stores Shortest Path Structure
        vector<int> value(n,INT_MAX);	//Keeps shortest path values to each vertex from source
        vector<bool> processed(n,false);	//TRUE->Vertex is processed

        //Assuming start point as Node-0
        parent[0] = -1;	//Start node has no parent
        value[0] = 0;	//start node has value=0 to get picked 1st

        //Include (V-1) edges to cover all V-vertices
        for(int i=0; i<n-1; ++i)
        {
            //Select best Vertex by applying greedy method
            auto function = [](int n, vector<int>& value,vector<bool>& processed) -> int {
                int minimum = INT_MAX;
                int vertex;
                for(int i=0; i < n; ++i)
                    if(processed[i]==false && value[i]<minimum){
                        vertex = i;
                        minimum = value[i];
                    }
                return vertex;
            };
            int U = function(n, value,processed);
            processed[U] = true;	//Include new Vertex in shortest Path Graph

            //Relax adjacent vertices (not yet included in shortest path graph)
            for(int j=0; j<n; ++j)
            {
                /* 3 conditions to relax:-
                    1.Edge is present from U to j.
                    2.Vertex j is not included in shortest path graph
                    3.Edge weight is smaller than current edge weight
                */
                if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX
                    && (value[U]+graph[U][j] < value[j]))
                {
                    value[j] = value[U]+graph[U][j];
                    parent[j] = U;
                }
            }
        }
        //Print Shortest Path Graph
        for(int i=1; i<n; ++i)
            cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";

        int count = 0;
        for(int node=0; node < n; ++node)
            if(node != u && parent[node] <= distanceThreshold)
                count++;    
        ans.push_back({count,u});
    }


    //using BFS + AdjList + PriorityQueue as MinHeap in O(E logV)
    // void dijkstra(vector<pair<int, int>> graph[], int u, int n, int distanceThreshold, vector<pair<int,int>>& ans){
        
    //     // use priority queue as min heap
    //     priority_queue<
    //         pair<int, int>, 
    //         vector<pair<int, int>>, 
    //         greater<pair<int, int>>
    //     > pq;
        
    //     // distance vector
    //     vector<int> distance(n+1, INT_MAX);

    //     pq.push(make_pair(0, u));
    //     distance[u] = 0;

    //     // normal BFS traversal
    //     while(!pq.empty()){

    //         int u = pq.top().second;
    //         pq.pop();

    //         // traverse for the neighbors of u
    //         for(auto it : graph[u]){

    //             int v = it.first;
    //             int w = it.second;

    //             if(distance[v] > distance[u] + w)
    //                 distance[v] = distance[u] + w,
    //                     pq.push(make_pair(distance[v], v));
    //         }
    //     }

    //     int count = 0;
    //     for(int node=0; node < n; ++node)
    //         if(node != u && distance[node] <= distanceThreshold)
    //             count++;    
    //     ans.push_back({count,u});
    // }

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

        // for each vertice
        for(int u=0; u < n; ++u)
            // using bfs
            //dijkstra(graph, u, n, distanceThreshold, ans);
            // using simple implementation
            _dijkstra(n, graph, u, distanceThreshold, ans);

    
        //anonymous class
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