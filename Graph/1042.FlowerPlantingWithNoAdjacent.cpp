#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
    }
};

int main()
{
    // adjacency edges
    vector<vector<int>> paths = { 
        {1,2},
        {2,3},
        {3,1}
    };
    int n = 3;

    Solution sl;
    for (auto it : sl.gardenNoAdj(n, paths))
        cout << it;
}