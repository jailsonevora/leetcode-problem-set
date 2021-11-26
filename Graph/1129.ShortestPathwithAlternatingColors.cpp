#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<pair<int,char>> graph[n+1];

        for(int i = 0; i < n; ++i)
            graph[red_edges[0][i]].push_back({red_edges[i][1],'r'}),
                graph[blue_edges[0][i]].push_back({blue_edges[i][1],'b'});
        
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