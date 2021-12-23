/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>

using namespace std;

// @lc code=start
class Solution {

    bool topDown(vector<int>& nums, int w, int n, vector<vector<int>>& dp){

        if(n==0)
            return 0;
        
        if(w == 0)
            return 1;

        if(dp[n-1][w] != -1)
            return dp[n-1][w];

        if(w < nums[n-1])
            return dp[n-1][w] = topDown(nums, w, n-1, dp);
        else
            return dp[n-1][w] = topDown(nums, w-nums[n-1], n-1, dp) || topDown(nums, w, n-1, dp);
    }

    // botton_up aproach dynamic programming tabulation
    bool bottonUp(vector<int> nums, int w, int n){

        int dp[n+1][w+1];

        for(int row = 0; row <= n; ++row)
            dp[row][0] = 1;
        for (int col = 1; col <= w; col++)
            dp[0][col] = 0;

        for(int row = 1; row <= n; ++row)
        {
            for (int col = 0; col <= w; col++)
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
        // print table
        // for (int i = 0; i <= n; i++) 
        // { 
        //     for (int j = 0; j <= w; j++) 
        //         printf ("%4d", dp[i][j]); 
        //     printf("\n"); 
        // }
        return dp[n][w];
    }

    // bit-manipulation
    bool bitManipulation_DP(vector<int> nums, int w, int n){
        
        for(int i=0; i<n; i++)
            w+= nums[i];
        
        if(w & 1)
            return 0;
        w = w/2;
        
        bitset<10001>dp;
        dp[0] = 1;
        for(int i =0; i<n; i++)
            dp = dp| (dp << nums[i]);
        return dp[w];
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int w = 0;
        w = std::accumulate(nums.begin(), nums.end(), w);

        // if w has decimal part it is not possible to form subset
        //if(w % 2 != 0)
        if(w & 1)
            return 0;

        // recursion + memo
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        w /= 2;
        return topDown(nums,w,n,dp);

        // dynamic programming tabulation aproach
        //return bottonUp(nums, w, n); 

        
    }
};
// @lc code=end

int main(){

    // ex1
    //vector<int> nums = {1,5,11,5};

    // ex2
    vector<int> nums = {1,2,3,5};

    Solution sl;
    cout << sl.canPartition(nums);
}

