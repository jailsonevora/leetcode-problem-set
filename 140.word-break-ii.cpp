/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // backtracking + memo 
    bool backtracking(vector<int>& dp, int i, string s, vector<string>& ans, string sentence, unordered_set<string> set){

        if(i == s.size()){
            ans.push_back(sentence);
            return true;
        }

        if(dp[i] == -1)
            return dp[i];

        for (int j = i+1; i < s.size(); j++)
            if(set.count(s.substr(i,j-i))) 
                if(backtracking(dp,j+1,s,ans,""+s.substr(i,j-i),set))
                    return dp[i] = true;
        return dp[i] = false;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        vector<string> ans;
        backtracking(dp,0,s,ans,"",set);
        return ans;
    }
};
// @lc code=end
int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};

    Solution sl;
    sl.wordBreak(s,wordDict);
}
