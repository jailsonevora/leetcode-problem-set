/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    void backtracking(vector<int>& nums, int k, int i, vector<int>& ans){

        if(i == nums.size()){
            ans.push_back(i);
        }
        else{
            for (int j = i+1; j < nums.size(); i++)
            {
                if(abs(nums[i]-nums[j]) == k)
                    backtracking(nums,k,i+1,ans);
                nums.pop_back();
            }            
        }

    }
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> ans;
        backtracking(nums,k,0,ans);
        return ans.size();        
    }
};
// @lc code=end
int main(){

    vector<int> nums = {1,2,2,1}; int k = 1;

    Solution sl;
    cout << sl.countKDifference(nums,k);
}
