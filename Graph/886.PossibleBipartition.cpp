#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int find(int v, vector<int> parent){
        if(v == parent[v])
            return v;
        return parent[v] = find(parent[v], parent);
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
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