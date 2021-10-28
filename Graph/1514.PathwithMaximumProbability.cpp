#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> edges = { 
        {0,1},
        {1,2},
        {0,2}
    };
    //weight or probability
    vector<double> succProb = { 
        0.5,
        0.5,
        0.2
    };
    int n = 3;

    // adjacency edges
    // vector<vector<int>> edges = { 
    //     {0,1},
    //     {1,2},
    //     {0,2}
    // };
    // //weight or probability
    // vector<double> succProb = { 
    //     0.5,
    //     0.5,
    //     0.3
    // };
    // int n = 3;

    // adjacency edges
    // vector<vector<int>> edges = { 
    //     {0,1}
    // };
    // //weight or probability
    // vector<double> succProb = { 
    //     0.5
    // };
    // int n = 3;


    Solution sl;
    std::cout << sl.maxProbability(n, edges, succProb, 0,1);
}