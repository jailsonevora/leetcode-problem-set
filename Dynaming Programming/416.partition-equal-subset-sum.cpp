/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// @lc code=start
class Solution {

    // botton_up aproach dynamic programming tabulation
    bool bottonUp(vector<int> nums, int w, int n){

        int dp[n+1][w+1];

        for(int row = 0; row < n; ++row)
            dp[row][0] = 1;
        for (int col = 0; col < w; col++)
            dp[0][col] = 0;

        for(int row = 1; row < n; ++row)
        {
            for (int col = 1; col < w; col++)
            {   
                // exclude
                if(col < nums[row-1])
                    dp[row][col] = dp[row-1][col];
                // include
                if(col >= nums[row-1])
                    // exclude num or include it
                    dp[row][col] = dp[row-1][col] || dp[row-1][col-nums[row-1]];   
            }            
        }
        return dp[n][w];
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int w = 0; 
        w = std::accumulate(nums.begin(), nums.end(), w)/2;

        // dynamic programming aproach
        return bottonUp(nums, w, n); 
    }
};
// @lc code=end

int main(){

    // ex1
    vector<int> nums = {1,5,11,5};

    // ex2
    //vector<int> nums = {1,2,3,5};

    Solution sl;
    cout << sl.canPartition(nums);
}

