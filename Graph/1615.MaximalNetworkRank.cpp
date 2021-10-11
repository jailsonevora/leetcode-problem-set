#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
    }
};

int main(){

    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    // adjacency matrix
    vector<vector<int>> roads = { 
        {0,1},
        {0,3},
        {1,2},
        {1,3}
    };
    int n = 4;

    Solution sl;

    for(auto q: sl.calcEquation(equations, values, queries))
        cout << q << "\n";

}