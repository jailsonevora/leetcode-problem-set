/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// @lc code=start
class Solution {

    // botton_up aproach dynamic programming tabulation
    bool bottonUp(vector<int> nums, int w, int n){

        int dp[n+1][w+1];

        for(int row = 0; row < n+1; ++row){
            for (int col = 0; col < w+1; col++)
            {
                /* code */
            }
            
        }

        return dp[n+1][w+1];
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int w = 0; 
        std::accumulate(nums.begin(), nums.end(), w);
        w /=2; 
        
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

