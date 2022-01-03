/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
    // inverting the vector aproach
    int invertingVector(vector<int>& nums){

        for (int i = 0; i < nums.size(); i++)
            nums[i]*=-1;

        

        

    }
    // kadanes algorithm
public:
    int maxSubarraySumCircular(vector<int>& nums) {



        
    }
};
// @lc code=end

int main(){
    vector<int> nums = {1,-2,3,-2};

    Solution sl;
    cout << sl.maxSubarraySumCircular(nums);
}

