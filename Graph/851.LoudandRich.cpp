#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
    }
};

int main()
{

    // // adjacency matrix
    // vector<vector<int>> roads = { 
    //     {0,1},
    //     {0,3},
    //     {1,2},
    //     {1,3},
    //     {2,3},
    //     {2,4}
    // };
    // int n = 5;

    // adjacency matrix
    vector<vector<int>> richer = { 
        {1,0},
        {2,1},
        {3,1},
        {3,7},
        {4,3},
        {5,3},
        {6,3}
    };
    int n = 8;

    Solution sl;

    cout << sl.maximalNetworkRank(n, roads);
}