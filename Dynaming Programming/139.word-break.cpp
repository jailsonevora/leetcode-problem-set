/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

// @lc code=start
class Solution {
    // DP tabulation
    bool bottomUp(string s, vector<string>& wordDict){
        int n = s.size();
        bool dp[n+1][n+1];
        
        unordered_set<string> myset;
        for(auto word: wordDict)
            myset.insert(word);
        
        for(int length=1;length<=n;++length) //Window Size
        {
            int start = 1;
            int end = length;
            while(end<=n) //Sliding Window
            {
                string temp = s.substr(start-1,length);
                if(myset.find(temp)!=myset.end())
                    dp[start][end] = true;
                else
                {
                    bool flag = false;
                    for(int i=start;i<end;++i)
                        if(dp[start][i] and dp[i+1][end])
                        {
                            flag = true;
                            break;
                        }
                    dp[start][end] = flag;
                }
                start += 1;
                end += 1;
            }
        }
        return dp[1][n];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return bottomUp(s, wordDict);
    }
};
// @lc code=end
int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};

    Solution sl;
    cout << sl.wordBreak(s, wordDict);
}

