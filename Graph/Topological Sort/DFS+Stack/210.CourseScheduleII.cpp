#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Util\Include\Graph.h"

using namespace std;

class Solution {
    // recursive check cycle
    bool dfs(int v, vector<vector<int>>& graph, vector<int> &discovered){

        if(discovered[v] == 1) // viseted
            return false;
        if(discovered[v] == 2) // processing
            return true;
        
        // mark the current node as processing
        discovered[v] = 2;

        // do for every edge `v —> u`
        for (int u: graph[v])
            if(dfs(u, graph, discovered))
                return true;
        
        discovered[v] = 1; // viseted
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                
        vector<int> discovered(numCourses, 0);

        for(int node = 0; node < numCourses; node++)
            if (!discovered[node])
                if(dfs(node, prerequisites, discovered))
                        return false;
        return true;
    }
    void _dfs(int u, vector<vector<int>>& graph, vector<int> &discovered, stack<int> &ans){

        discovered[u] = 1;
        for (int v : graph[u])
            if (!discovered[v])
                _dfs(v, graph, discovered, ans);
        ans.push(u);
    }
public:    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        //to convert edge list to adjacent matrix
        vector<vector<int>> graph(numCourses);
        for (auto &edge: prerequisites)
            graph[edge[1]].push_back(edge[0]);
        
        //check cycle
        if(!canFinish(numCourses, graph))
            return vector<int>{};

        stack<int> stack;
        vector<int> discovered(numCourses, 0);

        //for each unvisited node traverse and push to global stack
        for(int node = 0; node < numCourses; node++)
            if(!discovered[node])
                _dfs(node, graph, discovered, stack);      
        
        
        // reverse global stack when using dfs recursively
        vector<int> revereStack;
        while (!stack.empty()){
            revereStack.push_back(stack.top());
            stack.pop();
        }

        return revereStack;     
    }  
};

int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {1, 0}
    // };
    // int N = 2;

    // vector<Edge> edges = {
    //      {1,0},{2,0},{3,1},{3,2}
    // };
    // int N = 4;

    vector<Edge> edges = {
        
    };
    int N = 1;
 
    // build a graph from the given edges
    Graph graph(edges, N);
    
    Solution sl;
    for(auto v: sl.findOrder(N, graph.adjMatrix))
        cout << v << "\n";
}