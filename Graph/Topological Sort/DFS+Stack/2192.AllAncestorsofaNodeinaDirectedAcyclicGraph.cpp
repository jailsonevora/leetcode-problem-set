#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    void dfs(vector<int>& ans, vector<int> graph[], int u, vector<int>& visited){

        visited[u] = 1;
        for(int v: graph[u])
            if(!visited[v])
                dfs(ans,graph,v,visited);
        ans.push_back(u);
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<int> graph[n];
        vector<vector<int>> ancestors(n);

        // reverse each edge 
        for(auto edge: edges)
            graph[edge[1]].push_back(edge[0]);

        //now apply dfs on each node to find all node that connect to it
        vector<int> visited(n+1,0);

        for (int i = 0; i < n; i++){
            vector<int> ans;
            dfs(ans, graph, i, visited);
            sort(ans.begin(),ans.end());
            ancestors[i] = ans;
            visited.clear();
        }
        return ancestors;
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