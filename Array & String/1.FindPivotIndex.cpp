#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(sum == (total - sum - nums[i]))
                return i;
            sum += nums[i];
        }
        return -1;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<int> nums = {1,7,3,6,5,6};

    cout << sl.pivotIndex(nums);
}
