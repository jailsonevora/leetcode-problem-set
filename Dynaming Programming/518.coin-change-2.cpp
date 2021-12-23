/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    int bottomUp(vector<int> coins, int amount){

        int n = coins.size();

        int dp[n+1][amount+1];

        for (int row = 0; row <= n; row++)
            dp[row][0] = 1; 
        for (int col = 1; col <= amount; col++)
            dp[0][col] = 0;

        for (int row = 1; row <= n; row++)
            for (int col = 1; col <= amount; col++){
                // exclude
                if(col < coins[row-1])
                    dp[row][col] = dp[row-1][col];
                // include + exclude
                else
                    dp[row][col] = dp[row][col - coins[row-1]] + dp[row-1][col];
            }
        return dp[n][amount];
    }
public:
    int change(int amount, vector<int>& coins) {

        // bottom-Up
        return bottomUp(coins,amount);        
    }
};
// @lc code=end

int main(){
    
    vector<int> coins = {1,2,5};
    int amount = 5;

    Solution sl;
    cout << sl.change(amount,coins);
}

