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

    //one dimension DP problem
    bool wordBreak(string s, vector<string>& wd) {
        
        int n=s.size();
        vector<bool>dp(n,false);
        
        dp[0]=true;
        
        for(int i=0; i<n; i++){
            for(auto str:wd){
                if(dp[i]){
                    if(s.substr(i,str.size()).compare(str)==0){
                        dp[i+str.size()]=true;
                    }
                }
            }
        }
        return dp[n];
    }

    // backtracking && memoization
    bool backtrackingMemo(string& s, int i, vector<int>& dp, unordered_set<string>& set){

        if(i == s.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];

        for (int j = i+1; j <= s.size(); j++)
            if(set.count(s.substr(i,j-i)) && backtrackingMemo(s,j,dp,set))
                    return dp[i] = true;
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wd) {
        
        unordered_set<string> set;
        for(auto str: wd)
            set.insert(str);
        
        vector<int> dp(s.size(),-1);
        return backtrackingMemo(s,0,dp,set);
    }
};
// @lc code=end
int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};

    Solution sl;
    cout << sl.wordBreak(s,wordDict);
}
