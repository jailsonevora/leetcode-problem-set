#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);
        vector<vector<int>> edgepair(n, vector<int>(n,0)); //matrix values will set to 1 if the pair of cities has road between them

        for(auto edge: roads)
            degree[edge[0]]++, // no. of roads (incoming/outgoing) for a particular city
                degree[edge[1]]++, // no. of roads (incoming/outgoing) for a particular city
                    edgepair[edge[0]][edge[1]] = 1, //matrix values for pair of city set to 1
                        edgepair[edge[1]][edge[0]] = 1; //set 1 for both roads [ai,bi]
                         

        int maxRank = INT_MIN;

        // faster - for all pair of edge even if they do not have a direct connection
        for(int from = 0; from < n; from++)
            for(int to = from + 1; to < n; to++)
                    maxRank = std::max(degree[from] + degree[to] - edgepair[from][to], maxRank);

        // the same as above
        // for(int from = 0; from < n; from++)
        //     for(int to = from + 1; to < n; to++)
        //         if(edgepair[from][to] == 1) 
        //             maxRank = std::max((degree[from] + degree[to] - 1), maxRank);
        //         else
        //             maxRank = std::max((degree[from] + degree[to]), maxRank);

        // only for vertice with direct connection
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