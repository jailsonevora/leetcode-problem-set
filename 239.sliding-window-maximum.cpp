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
        
        int left = 0, right = k-1;
        vector<int> ans;

        while (right < nums.size())
        {
            /* code */
            int curr = left;
            priority_queue<int,vector<int>,less<int>> pq;
            while (curr <= right)
            {
                pq.push(nums[curr]);
                curr++;
            }
            ans.push_back(pq.top());
            left++, right++;
        }
        return ans;
    }
};
// @lc code=end
int main(){

    Solution sl;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    sl.maxSlidingWindow(nums,k);
}
