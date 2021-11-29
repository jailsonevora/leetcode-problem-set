#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {

    void bfs(vector<pair<int, char>> graph[], int start, int n, vector<int>& distance){

        vector<int> visited(n,0);

        queue<pair<int, pair<int,char>> > queue;
        distance[start] = 0;

        queue.push({0,{start,'n'}});

        while(!queue.empty()){

            int u = queue.front().second.first;
            char uColor = queue.front().second.second;
            queue.pop();

            for(auto it: graph[u]){

                int v = it.first;
                char vcolor = it.second;

                if(uColor != vcolor && visited[v] <= n){
                    
                    if(distance[v] > distance[u] + 1){
                        distance[v] = distance[u] + 1;
                    }
                    
                    queue.push({distance[v], {v,vcolor}});
                    visited[v] += 1;
                }
            }

            for(auto& a: distance){
                if(a == INT_MAX)
                    a = -1;
            }

        }

    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        // pair with vector
        // vector<vector<pair<int,char>>> graph[n];

        // for(auto edge: red_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u].push_back({{v,'r'}});
        // }

        // for(auto edge: blue_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u].push_back({{v,'b'}});
        // }

        // pair without vector
        vector<pair<int,char>> graph[n];

        for(auto edge: red_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,'r'});
        }

        for(auto edge: blue_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,'b'});
        }

        int w = 0;
        // vector<vector<char>> graph(n,vector<char>(n,'n'));

        // for(auto edge: red_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u][v] = 'r';
        // }

        // for(auto edge: blue_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u][v] = 'b';
        // }

        vector<int> ans(n, INT_MAX);
        
        bfs(graph, 0, n, ans);

        return ans;
    }
};

int main(){

    int n = 3;
    vector<vector<int>> red_edges = {
        {0,1},{1,2}
    };

    vector<vector<int>> blue_edges = {
    };

    Solution sl;
    sl.shortestAlternatingPaths(n, red_edges, blue_edges);
}