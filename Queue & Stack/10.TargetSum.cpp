#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int target, int sum, int pos, int& count){
        if(pos == nums.size()){
            if(sum == target) count++;
            return;
        }
        backtrack(nums, target, sum + nums[pos], pos + 1, count);
        backtrack(nums, target, sum - nums[pos], pos + 1, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, 0, 0, count);
        return count;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> nums = {1,1,1,1,1};
    int target = 3;
 
    Solution sl;
    cout << sl.findTargetSumWays(nums,target);
}