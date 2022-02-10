/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void backtracking(vector<int>& nums, int& ans){

        

    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        backtracking(nums,ans);
        return ans;
    }
};
// @lc code=end
int main(){

    vector<int> nums = {1,3};

    Solution sl;

    cout << sl.subsetXORSum(nums);
}

