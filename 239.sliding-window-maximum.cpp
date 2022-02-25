/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int left = 0, right = 2;
    }
};
// @lc code=end
int main(){

    Solution sl;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    sl.maxSlidingWindow(nums,k);
}
