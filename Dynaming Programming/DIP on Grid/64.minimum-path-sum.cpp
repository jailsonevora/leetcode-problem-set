/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    int bottomUp(vector<vector<int>>& grid){

        int m = grid.size(),
        n = grid[0].size();

        if(m==0)
            return 0;        
        
        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0] = grid[0][0];

        for (int row = 1; row < m; row++)
            dp[row][0] = dp[row-1][0] + grid[row][0];

        for (int col = 1; col < n; col++)
            dp[0][col] = dp[0][col-1] + grid[0][col];
        
        //Now fill the rest of the cell
        for (int row = 1; row < m; row++)
            for (int col = 1; col < n; col++)
                dp[row][col] = grid[row][col] + min(dp[row-1][col],dp[row][col-1]);
        return dp[m-1][n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return bottomUp(grid);
    }
};
// @lc code=end

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    Solution sl;
    cout << sl.minPathSum(grid);
}

