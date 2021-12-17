/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// @lc code=start
class Solution {
    //DP
    int bottomUp(vector<int> nums, int w, int n){

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        // bottom up DP
        return bottomUp(nums, target, n);        
    }
};
// @lc code=end

int main(){

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    Solution sl;
    cout << sl.findTargetSumWays(nums, target);
}

