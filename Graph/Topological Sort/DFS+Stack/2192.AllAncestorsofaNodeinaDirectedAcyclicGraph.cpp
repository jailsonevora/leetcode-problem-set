#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        //vector<int> graph[n], indegree[n];
        vector<vector<int>> indegree(n);

        for(auto edge: edges){
            //graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]].push_back(edge[0]);
        }

        return indegree;
        
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