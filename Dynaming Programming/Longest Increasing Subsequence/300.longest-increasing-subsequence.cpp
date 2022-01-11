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
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int dip[n]; 

        dip[0] = 1; 

        /* Compute optimized LIS values in bottom up manner */
        for (int i = 1; i < n; i++ ) 
        { 
            dip[i] = 1; 
            for (int j = 0; j < i; j++ ) 
                if ( nums[i] > nums[j] && dip[i] < dip[j] + 1) 
                    dip[i] = dip[j] + 1; 
        } 

        // Return maximum value in lis[] 
        return *max_element(dip, dip+n); 
    }
};
// @lc code=end

