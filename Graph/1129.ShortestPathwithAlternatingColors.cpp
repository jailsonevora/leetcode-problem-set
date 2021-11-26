#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<vector<pair<int,char>>> graph[n];

        for(auto edge: red_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({{v,'r'}});
        }

        for(auto edge: blue_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({{v,'b'}});
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

        return {};
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