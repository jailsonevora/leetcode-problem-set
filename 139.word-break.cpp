/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

// DP problem lcs->pattern matching variation and unbonded knapsack problem
class Solution {
public:
    // two dimension
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        unordered_set<string> set;
        for(string s: wordDict)
            set.insert(s);

        bool dp[n+1][n+1];
        int len = 1;

        while(len <= n)
        {   
            int left = 1, right = len;
            while(right <= n)
            {
                if(set.count(s.substr(left-1,len)))
                    dp[left][right] = true;
                else{
                        bool flag = false;
                        for(int i=left; i<right; ++i)
                            if(dp[left][i] && dp[i+1][right]){
                                flag = true;
                                break;
                            }                    
                        dp[left][right] = flag;
                    }
                left++;
                right++;
            }
            len++;
        }
        return dp[1][n];        
    }
};
// @lc code=end
int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};

    Solution sl;
    cout << sl.wordBreak(s,wordDict);
}
