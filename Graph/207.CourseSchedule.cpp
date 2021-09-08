#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class Solution {
    bool dfs(int v, vector<vector<int>>& graph, vector<bool> &discovered){

        if(discovered[v] == 1) // viseted
            return false;
        if(discovered[v] == 2) //processed
            return true;
        
        // mark the current node as discovered
        discovered[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, discovered))
                return true;
        
        discovered[v] = 1; //processed
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<vector<int>> graph(numCourses);
        for (auto &edge: prerequisites)
        {
             graph[edge[0]].push_back(edge[1]);
             //graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> discovered(numCourses, 0);

        
        for(int node = 0; node < numCourses; ++node)
            if (discovered[node] == 0)
                if(dfs(node, graph, discovered))
                    return false;
        return true;
    }   
};