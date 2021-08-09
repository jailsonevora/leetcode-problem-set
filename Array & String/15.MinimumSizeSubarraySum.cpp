#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int left = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans,i+1-left);
                sum-=nums[left];
                left++;
            }            
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    // int target = 7;
    // vector<int> nums = {2,3,1,2,4,3};
    // int target = 4;
    // vector<int> nums = {1,4,4};
    int target = 11;
    vector<int> nums = {1,1,1,1,1,1,1,1};

   cout << sl.minSubArrayLen(target, nums) << "\n";
}