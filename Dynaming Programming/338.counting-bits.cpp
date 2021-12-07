#include<iostream>
#include<vector>

using namespace std;
/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++){
            int d = i - (i & -i);
            dp[i] = dp[i - (i & -i)] + 1;
        }
        return dp;
    }
};
// @lc code=end

int main(){

    // ex1
    int n = 2;

    // ex2
    //int n = 5;

    Solution sl;
    sl.countBits(n);
}

