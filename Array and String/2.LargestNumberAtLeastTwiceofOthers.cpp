#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxDmy = -1;
        for (int i = 0; i < nums.size(); i++)
            if(maxDmy < nums[i] && nums[i] / 2 == maxDmy)
                maxDmy = nums[i];
        return maxDmy;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    //vector<int> nums = {3,6,1,0};
    //vector<int> nums = {1,2,3,4};
    vector<int> nums = {1};

    cout << sl.dominantIndex(nums);
}