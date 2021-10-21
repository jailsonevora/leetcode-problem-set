#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
    bool _dfs(int u, int v, vector<int> graph[], vector<int> visited){

        if(u == v)
            return true;
        
        if(visited[u])
            return false;

        visited[u] = 1;
        for(auto unext: graph[u])
            if(!visited[unext])
                if(_dfs(unext, v, graph, visited))
                    return true;
        return false;
    }

    void _bfs(int u, vector<int> graph[], vector<vector<int>>& reachable, vector<int> visited){

    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> graph[numCourses];

        for(auto edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);

        vector<int> visited(numCourses,0);
        vector<bool> ans;
        //vector<vector<int>> reachable(numCourses, vector<int>(numCourses,0));

        for(auto edge: queries)
            ans.push_back(_dfs(edge[0],edge[1], graph, visited));

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