/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

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
    int topDown(vector<int>& coins, int amount, int dp[][1001]){

        int n = coins.size();

        
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp tabulation
        //return bottomUP(coins,amount);

        // memo + recursion

    }
};
// @lc code=end

int main(){

    vector<int> coins = {1,2,5};
    int amount = 11;

    Solution sl;
    cout << sl.coinChange(coins, amount);
}

