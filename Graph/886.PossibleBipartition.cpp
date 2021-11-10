#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int find(int v, vector<int>& parent){
        if(v == parent[v])
            return v;
        return parent[v] = find(parent[v], parent);
    }

    void _union(int u, int v, vector<int>& parent, vector<int>& rank){

        if(rank[v] < rank[u])
            parent[v] = u;
        else if(rank[u] < rank[v])
            parent[u] = v;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> parent(n,0), rank(n,0);

        for(int i = 0; i < n; ++i)
            parent[i] = i;

        for(auto edge: dislikes){
            
        }
         
    }
};

int main()
{
    vector<vector<int>> dislikes = { 
        {1,2},
        {1,3},
        {2,4}
    };
    int n = 4;

    // vector<vector<int>> dislikes = { 
    //     {1,2},
    //     {1,3},
    //     {2,3}
    // };
    // int n = 3;

    // vector<vector<int>> dislikes = { 
    //      {1,2},
    //      {2,3],
    //      {3,4},
    //      {4,5},
    //      {1,5}
    // };
    // int n = 3;

    Solution sl;
    std::cout << sl.possibleBipartition(4, dislikes);
}