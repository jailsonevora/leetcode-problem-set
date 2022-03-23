#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& ans, vector<int> graph[], int u, vector<int> visited){

        visited[u] = 1;
        for(int v: graph[u])
            if(!visited[v]){
                dfs(ans,graph,v,visited);
                ans[u].push_back(v);
            }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<int> graph[n];
        vector<vector<int>> ans;

        // reverse each edge 
        for(auto edge: edges)
            graph[edge[1]].push_back(edge[0]);

        //now apply dfs on each node to find all node that connect to it
        vector<int> visted(n,0);

        for (int i = 0; i < n; i++)
            dfs(ans, graph, i, visted);
        return ans;
    }
};

int main(){

    int n = 8;
    vector<vector<int>> edgeList = {
        {0,3},
        {0,4},
        {1,3},
        {2,4},
        {2,7},
        {3,5},
        {3,6},
        {3,7},
        {4,6}
    };

    Solution sl;

    sl.getAncestors(n, edgeList);
}