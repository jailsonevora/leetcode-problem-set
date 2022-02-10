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

    void backtrackingWithoutFor(vector<int>& nums, int i, int temp, int& ans){

        if(i == nums.size()){
            ans += temp;
            return;
        }
        backtrackingWithoutFor(nums,i+1,temp,ans);
        temp ^= nums[i];
        backtrackingWithoutFor(nums,i+1,temp,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        backtrackingWithoutFor(nums,0,0,ans);
        return ans;
    }
};
// @lc code=end
int main(){

    //vector<int> nums = {1,3};
    vector<int> nums = {5,1,6};

    Solution sl;
    cout << sl.subsetXORSum(nums);
}

