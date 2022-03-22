#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<int> graph[n], indegree[n];

        // reverse each edge 
        for(auto edge: edges){
            graph[edge[1]].push_back(edge[0]);

        //now apply dfs on each node to find all node that connect to it
        
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