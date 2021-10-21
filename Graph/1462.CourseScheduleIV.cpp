#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
    void _bfs(){
        
        queue<int> queue;

        queue.push(i);

        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int nei : g[f]){
                if(ir[i][nei])
                    continue;
                ir[i][nei]=1;
                q.push(nei);
            }
        }

    }
    
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> graph[numCourses];

        for(auto edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);

        vector<bool> ans;
        vector<vector<int>> isReachable(numCourses,vector<int>(numCourses,0));

        for(int node = 0; node < numCourses; node++)
            _bfs(node, graph, isReachable);

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