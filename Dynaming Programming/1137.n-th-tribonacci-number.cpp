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
    // botton-up aproach Dynaming programming 1
    int bottonUP1(int n){

        vector<int> dp(n+1);

        if (n == 0)
            return 0;
        if (n == 1 or n == 2)
            return 1;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }

    int bottonUP2(int n) {
        int dp[] = {0, 1, 1};
        for (int i = 3; i <= n; ++i)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
    }

    // top-down aproach memoization
    int topDown(int n, int dp[]){

        if(n == 0)
            return 0;
        if (n == 1 or n == 2)
            return 1;

    }


public:
    int tribonacci(int n) {
        return bottonUP2(n);        
    }
};

// @lc code=end

int main(){
    // ex1
    //int n = 4;

    // ex2
    int n = 25;

    Solution sl;
    cout << sl.tribonacci(n);
}