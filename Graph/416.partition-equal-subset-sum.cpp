/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int w =  std::accumulate(nums.begin(), nums.end()) /2;
        
    }
};
// @lc code=end

int main(){

    // ex1
    vector<int> nums = {1,5,11,5};

    // ex2
    // vector<int> nums = {1,2,3,5};

    Solution sl;
    cout << sl.canPartition(nums);
}

