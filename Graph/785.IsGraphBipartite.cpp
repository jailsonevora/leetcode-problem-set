#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
    // find path compression
    int _find(int v, vector<int>& parent){

        if(v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent); // path compression
    }
    // union by rank
    void _union(int from, int to, vector<int>& parent, vector<int>& rank){
        
        if(rank[to] < rank[from])
            parent[to] = from;
        else if(rank[from] < rank[to])
            parent[from] = to;
        else
        {
            parent[to] = from;
            rank[from]++;
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> edges = { 
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int n = 4, distanceThreshold = 4;

    Solution sl;
    std::cout << sl.findTheCity(n, edges, distanceThreshold);
}