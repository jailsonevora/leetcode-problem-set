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
    // kadanes algorithm
    int kadanesAlgorithm(vector<int>& nums){

        int max_straight_SUM = INT_MIN, min_straight_SUM = INT_MAX, array_SUM = 0;
        
        int temp_maxSUM = 0, temp_minSUM = 0;
        for(int i = 0; i < nums.size(); ++i){
            array_SUM +=nums[i];
            
            temp_maxSUM += nums[i];
            max_straight_SUM = max_straight_SUM<temp_maxSUM? temp_maxSUM:max_straight_SUM;
            temp_maxSUM = temp_maxSUM<0?0:temp_maxSUM;
            
            temp_minSUM += nums[i];
            min_straight_SUM = min_straight_SUM>temp_minSUM? temp_minSUM:min_straight_SUM;
            temp_minSUM = temp_minSUM>0?0:temp_minSUM;
        }
        if(array_SUM==min_straight_SUM)
            return max_straight_SUM;
        return max(max_straight_SUM,(array_SUM-min_straight_SUM));
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {

        //return invertingVector(nums);        
    }
};
// @lc code=end

int main(){
    vector<int> nums = {1,-2,3,-2};

    Solution sl;
    cout << sl.maxSubarraySumCircular(nums);
}

