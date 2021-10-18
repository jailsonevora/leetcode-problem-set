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

        // initialize leads
        vector<int> parent(graph.size(), 0);
        vector<int> rank(graph.size(), 0);

        // intantiate the rankings and parents
        for (int i = 0; i < graph.size(); i++)
            parent[i] = i, 
                rank[i] = 0;

        // all node neighbours should belong to one set
        for(int row = 0; row < graph.size(); row++){
            for(int col = 0; col < graph[row].size(); col++){
                
                int absPFrom = _find(row, parent);
                int absPTo = _find(graph[row][col], parent);

                if(absPFrom == absPTo)
                    return false;
                _union(_find(graph[row][0], parent), _find(graph[row][col], parent), parent, rank);
            }
        }
        return true;
    }
};

int main()
{
    // adjacency Matrix
    vector<vector<int>> graph = { 
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };

    // adjacency Matrix
    // vector<vector<int>> graph = { 
    //     {1,3},
    //     {0,2},
    //     {1,3},
    //     {0,2}
    // };

    Solution sl;
    std::cout << sl.isBipartite(graph);
}