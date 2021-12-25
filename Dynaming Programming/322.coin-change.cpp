/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string.h>

using namespace std;

// @lc code=start
class Solution {
    // DP bottom-UP tabulation
    int bottomUP(vector<int> coins, int amount){
        
        int n = coins.size();

        // dp table
        int dp[n+1][amount+1];

        for (int row = 0; row <= n; row++)
            dp[row][0] = 0;
        for (int col = 1; col <= amount; col++)
            dp[0][col] = 1e5; 

        for (int row = 1; row <= n; row++)
            for (int col = 1; col <= amount; col++){                
                // exclude
                if(col < coins[row-1])
                    dp[row][col] = dp[row-1][col];
                // include or exclude
                else
                    dp[row][col] = min(1+dp[row][col-coins[row-1]], dp[row-1][col]);
            }
        return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
    } 

    // backtracking + memoization
    int topDown(vector<int>& coins, int n, int amount, int dp[][10001]){

        if(amount==0)
            return 0;

        if(amount < 0 || n < 0)
            return 1e5;

        if(dp[n][amount] != -1)
            return dp[n][amount];

        if(amount < coins[n-1])
            return dp[n][amount] = topDown(coins, n-1, amount, dp); 
        else
            return dp[n][amount] = min(1+topDown(coins, n, amount-coins[n-1], dp), topDown(coins, n-1, amount, dp));  
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp tabulation
        //return bottomUP(coins,amount);

        // memo + recursion
        int dp[1001][1001];
        memset(dp,-1, sizeof dp);
        return topDown(coins, coins.size(), amount, dp);
    }
};
// @lc code=end

int main(){

    vector<int> coins = {1,2,5};
    int amount = 11;

    Solution sl;
    cout << sl.coinChange(coins, amount);
}

