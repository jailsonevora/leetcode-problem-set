#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxDmy = -1, prevMax = -1, index = 0;
        for (int i = 0; i < nums.size(); i++)
            if(maxDmy < nums[i]){
                prevMax = maxDmy;
                maxDmy = nums[i];
                index = i;
            }
            else if(prevMax < nums[i]){
                prevMax = nums[i];
            }
        return maxDmy >= prevMax * 2 ? index : -1;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<int> nums = {3,6,1,0};
    //vector<int> nums = {1,2,3,4};

    cout << sl.dominantIndex(nums);
}