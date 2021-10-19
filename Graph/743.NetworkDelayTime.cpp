#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>> graph;
    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> times = { 
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n = 4, k = 2;
    
    Solution sl;
    cout << sl.networkDelayTime(times, n, k);
}