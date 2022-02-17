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
    // backtracking 
    void backtracking(int i, string& s, vector<string>& ans, string sentence, unordered_set<string> set){

        if(i == s.size()){
            ans.push_back(sentence);
            return;
        }
        else{
            if(!sentence.empty())
                sentence += " ";
            for (int j = i; j < s.size(); j++){
                if(set.count(s.substr(i,j+1-i)))
                    backtracking(j+1,s,ans,sentence+s.substr(i,j+1-i),set);
            }
        }
    }  
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<string> ans;
        backtracking(0,s,ans,"",set);
        return ans;
    }

    //one dimension DP problem
    // bool wordBreak(string s, vector<string>& wd) {
        
    //     int n=s.size();
    //     vector<bool>dp(n,false);
    //     vector<string> ans;
    //     string sentence = "";
        
    //     dp[0]=true;
        
    //     for(int i=0; i<n; i++){
    //         for(auto str:wd){
    //             if(dp[i]){
    //                 if(s.substr(i,str.size()).compare(str)==0){
    //                     dp[i+str.size()]=true;
    //                     sentence+=str;
    //                 }
    //             }
    //             ans.push_back(sentence);
    //         }
    //     }
    //     return dp[n];
    // }
};
// @lc code=end
int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};

    Solution sl;
    sl.wordBreak(s,wordDict);
}
