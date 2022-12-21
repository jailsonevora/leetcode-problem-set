/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * {200} Number of Islands
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    // dfs on grid
    void dfsOnGrid(int m, int n, int r, int c, vector<vector<char>>& grid){

        if(r >= m || c >= n || r < 0 || c < 0 || grid[r][c] != '1')
            return;

        grid[r][c] = '2';

        dfsOnGrid(m,n,r-1,c,grid); // up 
        dfsOnGrid(m,n,r+1,c,grid); // down
        dfsOnGrid(m,n,r,c-1,grid); // left
        dfsOnGrid(m,n,r,c+1,grid); // right

    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size(), 
        ans = 0;
        
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++){
                if(grid[r][c] == '1'){
                    dfsOnGrid(m,n,r,c,grid);
                    ans++;
                }
            }
        return ans;
    }
};
// @lc code=end
int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    Solution sl;
    cout << sl.numIslands(grid);
}

