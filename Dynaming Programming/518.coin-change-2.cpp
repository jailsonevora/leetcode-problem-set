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

    }
public:
    int change(int amount, vector<int>& coins) {
        
    }
};
// @lc code=end

int main(){
    
    vector<int> coins = {1,2,5};
    int amount = 5;

    Solution sl;
    cout << sl.change(amount,coins);
}

