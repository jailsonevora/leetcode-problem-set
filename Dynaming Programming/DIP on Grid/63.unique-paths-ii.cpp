/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    int bottomUp(vector<vector<int>>& obstacleGrid){
        
        int m = obstacleGrid.size(),
        n = obstacleGrid[0].size();
        int dp[m][n];

        for (int row = 0; row < m; row++)
            dp[row][0] = 1;

        for (int col = 1; col < n; col++)
            dp[0][col] = 1;

        for (int row = 1; row < m; row++)
            for (int col = 1; col < n; col++)
                dp[row][col] = dp[row][col-1] + dp[row-1][col];

        return dp[m-1][n-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
    }
};
// @lc code=end

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    Solution sl;
    cout << sl.uniquePathsWithObstacles(obstacleGrid);
}
