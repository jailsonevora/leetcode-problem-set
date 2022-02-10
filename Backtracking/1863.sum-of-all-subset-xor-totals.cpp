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
    void backtracking(vector<int>& nums, int i, int& ans){

        int temp = 0;
        if(i == nums.size()){
            ans += temp; 
        }
        else{
            for (int j = i; j < nums.size(); j++)
            {
                temp += nums[j];
                backtracking(nums,i+1,ans);
                nums.pop_back();
            }            
        }

    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        backtracking(nums,0,ans);
        return ans;
    }
};
// @lc code=end
int main(){

    vector<int> nums = {1,3};

    Solution sl;

    cout << sl.subsetXORSum(nums);
}

