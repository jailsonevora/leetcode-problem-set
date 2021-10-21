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
            return 1;
        
        if(visited[u])
            return 0;

        visited[u] = 1;
        for(auto unext: graph[u])
            if(!visited[v])
                if(_dfs(unext, v, graph, visited))
                    return true;
        return false;
    }

    void _bfs(int u, vector<int> graph[], vector<vector<int>>& reachable, vector<int> visited){

    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> graph[numCourses-1];

        for(auto edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);

        vector<int> visited;
        //vector<vector<int>> reachable(numCourses, vector<int>(numCourses,0));

        for(int node = 0; node < numCourses; ++node)
            

        
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
    int numCourses = 4;

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