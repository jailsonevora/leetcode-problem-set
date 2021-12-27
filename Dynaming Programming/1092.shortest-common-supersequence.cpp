/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
    string longestCommonSubsequence(string str1, string str2){
        int lenght1 = str1.size();
        int lenght2 = str2.size();

        string dp[lenght1+1][lenght2+1];

        for (int row = 0; row <= lenght1; row++)
            dp[row][0] = "";
        for (int col = 1; col <= lenght2; col++)
            dp[0][col] = "";

        for (int row = 1; row <= lenght1; row++)
            for (int col = 1; col <= lenght2; col++){
                // diogonal cel + 1
                if(str1[row-1] == str2[col-1])
                    dp[row][col] = dp[row-1][col-1] + str1[row-1];
                // else it is max of left or above cell
                else
                    dp[row][col] = dp[row][col-1].size() > dp[row-1][col].size() ? dp[row][col-1] : dp[row-1][col];
            }
        return dp[lenght1][lenght2];
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lCSubsequence = longestCommonSubsequence(str1,str2);

        int ptr1 = 0, ptr2 = 0;
        for(char ch: lCSubsequence){

            while (str1[ptr1] != ch)
                ans += str1[ptr1++];
            
        }
    }
};
// @lc code=end

int main(){

    string str1 = "abac", str2 = "cab";

    Solution sl;
    cout << sl.shortestCommonSupersequence(str1,str2);
}

