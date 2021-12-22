/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
    // bottom up DP tabulation
    int bottomUp(string text1, string text2){

        int s1 = text1.size(), s2 = text2.size();

        int dp[s1+1][s2+1];

        for (int row = 0; row <= s1; row++)
            dp[row][0] = 0;
        for (int col = 1; col <= s2; col++)
            dp[0][col] = 0;

        for (int row = 1; row <= s1; row++)
            for (int col = 1; col <= s2; col++){
                // diogonal cel + 1
                if(text1[row-1] == text2[col-1])
                    dp[row][col] = 1 + dp[row-1][col-1];
                // else it is max of left or above cell
                else
                    dp[row][col] = max(dp[row-1][col],dp[row][col-1]);
            }
        return dp[s1][s2];
    }
    // top-down recursion + memo
    int topDown(string text1, string text2){
        return 0;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // DP tabulation
        return bottomUp(text1,text2);

        // recursion + memo
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return topDown(text1,text2, text1.size(), text2.size(), dp);
    }
};
// @lc code=end

int main(){

    string text1 = "abcde", text2 = "ace";

    Solution sl;
    cout << sl.longestCommonSubsequence(text1,text2);  
}

