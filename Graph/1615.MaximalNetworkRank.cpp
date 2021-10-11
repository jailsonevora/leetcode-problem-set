#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n + 1, 0);

        for(auto edge: roads)
            degree[edge[0]]++,
                degree[edge[1]]++;

        int maxRank = INT_MIN;

        for(int from = 0; from < n && from < roads.size(); from++)
            for(int to = from + 1; to < n; to++)
                if(roads[from][to] == from && roads[to][from] == to)
                    maxRank = std::max((degree[from] + degree[to] - 1), maxRank);
                else
                    maxRank = std::max((degree[from] + degree[to]), maxRank);


        // for(auto edge: roads)
        //     maxRank = std::max((degree[edge[0]] + degree[edge[1]] - 1), maxRank);

        return maxRank;
    }
};

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