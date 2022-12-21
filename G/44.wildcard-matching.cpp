/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

// DP problem longest common subsequence lcs
class Solution {
public:
    // bottomUp approach
    bool isMatch(string s, string p) {

        int n = s.size(), w = p.size();
        
        int dp[n+1][w+1];
        std::fill(dp[0],dp[n+1],false);

        dp[0][0] = 1;
        for(int col = 1; col <= w; ++col)
            dp[0][col] = dp[0][col-1] && p[col-1] == '*';

        for(int row = 1; row <= n; ++row)
            for(int col = 1; col <= w; ++col){
                // exclude
                if(p[col-1] == '?' || s[row-1] == p[col-1])
                    dp[row][col] = dp[row-1][col-1];
                // include
                else if(p[col-1] == '*')
                    dp[row][col] = dp[row-1][col] || dp[row][col-1];
            }
        return dp[n][w];
    }
};
// @lc code=end
int main(){

    //string s = "aa", p = "a";
    string s = "aa", p = "*";

    Solution sl;
    cout << sl.isMatch(s,p);
}
