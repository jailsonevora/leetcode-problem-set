/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // DP LIS Longest increasing subsequence
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n]; 

        dp[0] = 1; 

        /* Compute optimized LIS values in bottom up manner */
        for (int i = 1; i < n; i++ ) 
        { 
            dp[i] = 1; 
            for (int j = 0; j < i; j++ ) 
                if ( nums[i] > nums[j] && dp[i] < dp[j] + 1) 
                    dp[i] = dp[j] + 1; 
        } 

        // Return maximum value in lis[] 
        return *max_element(dp, dp+n); 
    }

    //
    // DP Maximum Sum Increasing Subsequence MSIS
    // int maxSubArray(vector<int>& nums) {

    //     int n = nums.size();
    //     int dp[n];

    //     // initialize dp array
    //     for (int i = 0; i < n; i++)
    //         dp[i] = nums[i];

    //     for (int i = 1; i < n; i++)
    //         for (int j = 0; j < i; j++)
    //             if(nums[i] > nums[j] && dp[i] < dp[j] + nums[i])
    //                 dp[i] = dp[j] + nums[i];
    //     return *max_element(dp, dp+n);      
    // }
};
// @lc code=end

