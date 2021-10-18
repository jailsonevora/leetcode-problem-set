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