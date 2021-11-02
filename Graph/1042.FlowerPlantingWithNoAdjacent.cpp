#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> graph[n];

        for(auto edge: paths)
            graph[edge[0]].push_back(edge[1]),
                graph[edge[0]].push_back(edge[1]);

        
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> paths = { 
        {1,2},
        {2,3},
        {3,1}
    };
    int n = 3;

    Solution sl;
    for (auto it : sl.gardenNoAdj(n, paths))
        cout << it;
}