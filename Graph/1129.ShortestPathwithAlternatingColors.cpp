#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
    }
};

int main(){

    int n = 3;
    vector<vector<int>> red_edges = {
        {0,1},{1,2}
    };

    vector<vector<int>> blue_edges = {
    };

    Solution sl;
    sl.shortestAlternatingPaths(n, red_edges, blue_edges);
}