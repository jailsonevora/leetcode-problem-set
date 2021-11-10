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
        vector<int> graph[n];

        for(auto edge: dislikes)
            graph[edge[0]-1].push_back(edge[1]-1),
            graph[edge[1]-1].push_back(edge[0]-1);

        for(int i = 0; i < n; ++i)
            parent[i] = i;
        
        for(int u = 0; u < n; ++u){
            for(auto v: graph[u]){
                int absFrom = find(u,parent);
                int absTo = find(v,parent);

                if(absFrom == absTo)
                    return false;
    
                _union(absFrom, absTo, parent, rank);
            }
        }
        return false;
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