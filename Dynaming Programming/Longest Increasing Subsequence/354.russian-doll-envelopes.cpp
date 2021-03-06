/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

// @lc code=start
// longest increasing subsequence
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        if(n == 0)
            return 0;
        
        // int dp[n+1];
        // std::fill(dp, dp+n+1, 1);
        // //memset(dp, 1, sizeof(dp));

        vector<int> dp(n+1,1);

        sort(envelopes.begin(), envelopes.end());
        //int max = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]
                    && 1 + dp[j] > dp[i])
                        dp[i] = 1 + dp[j];
                // if(max < dp[i])
                //     max = dp[i];
            }
        }
        // for max atribute
            //return max;
        // for vector    
            return *std::max_element(dp.begin(), dp.end());
        // for array
            //return *std::max_element(dp, dp+n+1);
    }
};
// @lc code=end

int main(){

    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

    Solution sl;
    cout << sl.maxEnvelopes(envelopes);
}

