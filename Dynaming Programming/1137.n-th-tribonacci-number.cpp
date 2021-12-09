/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    // botton-up aproach Dynaming programming
    int bottonUP(int n){

        vector<int> dp(n);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i < n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }

    // top-down aproach memoization

public:
    int tribonacci(int n) {

        return bottonUP(n);        
    }
};

int main(){
    // ex1
    int n = 4;

    // ex2
    //int n = 25;

    Solution sl;
    sl.tribonacci(n);
}

// @lc code=end

