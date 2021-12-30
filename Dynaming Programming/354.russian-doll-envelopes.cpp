/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// @lc code=start
// longest increasing subsequence
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        if(n == 0)
            return 0;
        
    }
};
// @lc code=end

int main(){

    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

    Solution sl;
    cout << sl.maxEnvelopes(envelopes);
}

