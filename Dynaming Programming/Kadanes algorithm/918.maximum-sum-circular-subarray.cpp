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
    // kadanes algorithm + inverting the vector aproach
    int invertingVector(vector<int>& nums){

        for (int i = 0; i < nums.size(); i++)
            nums[i]*=-1;

        int arr_sum = accumulate(nums.begin(), nums.end(),0);

        int maxnd = 0, maxsfar = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            maxnd = maxnd + nums[i];
            if(maxnd < nums[i])
                maxnd = nums[i];
            if(maxsfar < maxnd)
                maxsfar = maxnd;
        }
        return max(arr_sum,maxsfar);
    }
    // kadanes algorithm
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        return invertingVector(nums);        
    }
};
// @lc code=end

int main(){
    vector<int> nums = {1,-2,3,-2};

    Solution sl;
    cout << sl.maxSubarraySumCircular(nums);
}

