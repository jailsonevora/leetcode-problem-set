#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

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