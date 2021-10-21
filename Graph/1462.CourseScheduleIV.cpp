#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
    // with dynamming programing
    bool _dfs(int u, int v, vector<int> graph[], vector<vector<int>>& dp){

        if (dp[u][v] != -1)
            return dp[u][v];

        for (int i = 0; i < graph[u].size(); i++)
            if(graph[u][i] == v || _dfs(dp[u][i], v, graph, dp))
                return dp[u][v] = 1;
        return dp[u][v] = 0;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> graph[numCourses];
        vector<vector<int>>dp(numCourses, vector<int>(numCourses, -1));

        for(auto edge: prerequisites)
            graph[edge[0]].push_back(edge[1]),
                dp[edge[0]][edge[1]] = 1;

        vector<int> visited(numCourses,0);
        vector<bool> ans;

        for(auto edge: queries)
            ans.push_back(_dfs(edge[0],edge[1], graph, dp));
        return ans;
    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> prerequisites = { 
        {1,0}
    };

    vector<vector<int>> queries = { 
        {0,1},
        {1,0}
    };
    int numCourses = 2;

    // vector<vector<int>> prerequisites = {
    // };

    // vector<vector<int>> queries = { 
    //     {1,0},
    //     {0,1}
    // };
    // int numCourses = 2;

    // vector<vector<int>> prerequisites = {
        // {1,2},
        // {1,0},
        // {2,0}
    // };

    // vector<vector<int>> queries = { 
    //     {1,0},
    //     {1,2}
    // };
    // int numCourses = 3;
    
    Solution sl;
    for(auto it: sl.checkIfPrerequisite(numCourses, prerequisites, queries))
        cout << it << "\n";
}