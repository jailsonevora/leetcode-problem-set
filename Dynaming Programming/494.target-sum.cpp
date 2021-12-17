/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// @lc code=start
class Solution {
    //DP
    int bottomUp(vector<int> nums, int w, int n){

        int dp[n+1][w+1];

        for (int row = 0; row < n; row++)
            dp[row][0] = 1;
        for (int col = 0; col < n; col++)
            dp[0][col] = 0;

        for(int row = 1; row <= n; ++row)
            for (int col = 1; col <= w; col++)
            {   
                // exclude
                if(col < nums[row-1])
                    dp[row][col] = dp[row-1][col];
                // include
                if(col >= nums[row-1])
                    // sum exclude num + include num
                    dp[row][col] = dp[row-1][col] + dp[row-1][col-nums[row-1]];   
            }
        return dp[n][w];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        // bottom up DP
        return bottomUp(nums, target, n);        
    }
};
// @lc code=end

int main(){

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    Solution sl;
    cout << sl.findTargetSumWays(nums, target);
}

