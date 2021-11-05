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
        time[0] = 0;

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();

            for(int v: graph[u]){
                if(time[v] == -1) // if not visited.
                    time[v] = time[u] + 1, // calc time for child node
                        queue.push(v);
            }
        }

        int res = 0;
        for(int i = 1; i < patience.size(); i++) {
            int extraPayload = (time[i] * 2 - 1)/patience[i];
			
            int lastOut = extraPayload * patience[i]; // find the last time when a data server sends a message
            int lastIn = lastOut + time[i] * 2; // this is the result for current data server
			
            res = max(res, lastIn);
        }
		
        return res+1;
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