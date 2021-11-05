#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        
        queue<int> queue;
        vector<int> time(patience.size(),-1);

        vector<int> graph[patience.size()];

        for(auto edge: edges)
            graph[edge[0]].push_back(edge[1]),
                graph[edge[1]].push_back(edge[0]);

        queue.push(0);

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();

            for(int v: edges[u]){

            }

        }
        

        
    }
};

int main(){

    vector<vector<int>> edges = {
        {0,1},{1,2}
    };

    vector<int> patience = {
        {0,2,1}
    };

    Solution sl;
    cout << sl.networkBecomesIdle(edges,patience);
}