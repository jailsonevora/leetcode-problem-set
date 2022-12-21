#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {

    void bfs(vector<pair<int, int>> graph[], int start, int n, vector<int>& distance){

        queue<pair<int, pair<int,int>> > queue;
        distance[start] = 0;

        queue.push({0,{start,-1}});

        while(!queue.empty()){

            int uDist = queue.front().first;
            int u = queue.front().second.first;
            char uColor = queue.front().second.second;
            queue.pop();

            for(auto& it: graph[u]){

                int v = it.first;
                char vcolor = it.second;

                if(uColor != vcolor && vcolor != -1){
                    
                    if(distance[v] > uDist + 1)
                        distance[v] = uDist + 1;
                    
                    queue.push({uDist+1, {v,vcolor}});
                    it.second = -1;
                }
            }
        }

        for(auto& a: distance)
            if(a == INT_MAX)
                a = -1;
    }

    void dijkstra(vector<pair<int, int>> graph[], int start, int n, vector<int>& distance){

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> queue;
        distance[start] = 0;

        queue.push({0,{start,-1}});

        while(!queue.empty()){

            int uDist = queue.top().first;
            int u = queue.top().second.first;
            int uColor = queue.top().second.second;
            queue.pop();

            for(auto& it: graph[u]){

                int v = it.first;
                int vcolor = it.second;

                if(uColor != vcolor && vcolor != -1){

                    if(distance[v] == -1)
                        distance[v] = uDist+1;
                    
                    queue.push({uDist+1, {v,vcolor}});
                    it.second = -1;
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<pair<int,int>> graph[n];

        for(auto edge: red_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,1});
        }

        for(auto edge: blue_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,0});
        }

        // bfs
        vector<int> ans(n,INT_MAX);
        bfs(graph, 0, n, ans);

        // dijkstra
        // vector<int> ans(n,-1);
        // dijkstra(graph, 0, n, ans);

        return ans;
    }
};

int main(){

    // int n = 3;
    // vector<vector<int>> red_edges = {
    //     {0,1},{1,2}
    // };

    // vector<vector<int>> blue_edges = {
    // };

    // int n = 3;
    // vector<vector<int>> red_edges = {
    //     {0,1}
    // };

    // vector<vector<int>> blue_edges = {
    //     {2,1}
    // };

    // int n = 3;
    // vector<vector<int>> red_edges = {
    //     {1,0}
    // };

    // vector<vector<int>> blue_edges = {
    //     {2,1}
    // };

    // int n = 3;
    // vector<vector<int>> red_edges = {
    //     {0,1}
    // };

    // vector<vector<int>> blue_edges = {
    //     {1,2}
    // };

    int n = 5;
    vector<vector<int>> red_edges = {
        {0,1},{1,2},{2,3},{3,4}
    };

    vector<vector<int>> blue_edges = {
        {1,2},{2,3},{3,1}
    };

    Solution sl;
    sl.shortestAlternatingPaths(n, red_edges, blue_edges);
}