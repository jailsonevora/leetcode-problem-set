#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Util\Include\Graph.h"

using namespace std;

class Solution {
    int _find(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent);
    }

    void _union(int from, int to, vector<int>& parent, int & ans) {
        from = _find(from, parent);
        to = _find(to, parent);
        if (from != to){
            parent[to] = from;
            ans++;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        // initialize leads
        vector<int> parent(n, 0); int ans = 0;
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int row = 0; row < n; row++)
            for (int col = 1; col < n; col++)
                if(stones[row][0] == stones[col][0] 
                || stones[row][1] == stones[col][1])            
                    _union(row, col, parent, ans);
        return ans;
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

    // vector<Edge> edges = {
        
    // };
    // int N = 1;
 
    // build a graph from the given edges
    //Graph graph(edges, N);

    // vector<vector<int>> edge = { 
    //     {1,2},
    //     {1,3},
    //     {2,3}
    // };

    vector<vector<int>> edge = { 
        {0,0},
        {0,1},
        {1,0},
        {1,2},
        {2,1},
        {2,2}
    };
    
    Solution sl;
    cout << sl.removeStones(edge) << "\n";
}