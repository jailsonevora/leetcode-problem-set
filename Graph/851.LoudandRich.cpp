#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{

    // adjacency matrix
    // vector<vector<int>> roads = { 
    //     {0,1},
    //     {0,3},
    //     {1,2},
    //     {1,3}
    // };
    // int n = 4;

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
    vector<vector<int>> roads = { 
        {0,1},
        {1,2},
        {2,3},
        {2,4},
        {5,6},
        {5,7}
    };
    int n = 8;

    Solution sl;

    cout << sl.maximalNetworkRank(n, roads);
}