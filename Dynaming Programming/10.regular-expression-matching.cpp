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

        for(int col = 2; col <= w; ++col)
            dp[0][col] = dp[0][col-2] && p[col-1] == '*';

        for(int row = 1; row <= n; ++row)
            for(int col = 1; col <= w; ++col){
                if(p[col-1] == '.' || (p[col-1] >= 'a' && p[col-1] <= 'z' && s[row-1]==p[col-1]) )
                    dp[row][col] = dp[row-1][col-1];
                else if(col > 1)
                {
                    if(s[row-1]==p[col-2] || p[col-2]=='.') 
                        dp[row][col] = dp[row-1][col] | dp[row][col-2];
                    else 
                        dp[row][col] = dp[row][col-2];
                }  
            }
        return dp[n][w];
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

