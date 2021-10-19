#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    void dfs(int u, vector<vector<int>> graph, vector<int>& visited){



    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // adj Matrix graph
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<int> outdegree(n,0), visited(n,0);

        for(auto edge: times)
            graph[edge[0]][edge[1]] = edge[2],
            outdegree[edge[0]]++;

        sort(outdegree.begin(),outdegree.end(), greater<>());

        int i = 0;
        if(!visited[k])
            dfs(outdegree[i], graph, visited);
        

        return 1;

    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> times = { 
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n = 4, k = 2;
    
    Solution sl;
    cout << sl.networkDelayTime(times, n, k);
}