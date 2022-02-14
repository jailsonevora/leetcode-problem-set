/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += (mp[nums[i]-k] + mp[nums[i]+k]);
            mp[nums[i]]++;
        }
        return ans;        
    }
};
// @lc code=end
int main(){

    vector<int> nums = {1,2,2,1}; int k = 1;

    Solution sl;
    cout << sl.countKDifference(nums,k);
}
