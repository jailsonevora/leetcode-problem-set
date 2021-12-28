/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

// @lc code=start
class Solution {
    // bottom-Up aproach dp tabulation
    bool bottomUp(string s, string p){

        int n = s.size(), w = p.size();

        int dp[n+1][w+1];
        memset(dp,-1,sizeof dp);

        dp[n][w] = 0;

        for(int row = 0; row <= n; ++row)
            dp[row][0]

    }

    // top-down aproach memoization
    
public:
    bool isMatch(string s, string p) {
        
        // bottom-Up aproach dp tabulation
        return bottomUp(s,p);
    }
};
// @lc code=end

int main(){
    
    string s = "aa", p = "a";



}

