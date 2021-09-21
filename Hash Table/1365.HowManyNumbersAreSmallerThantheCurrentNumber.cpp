#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        
        // brute force
        for(int i = 0; i < nums.size(); ++i)
            for(int j = 1; j < nums.size(); j++)
                if(nums[j] < nums[i])
                    ans[i]++;
        
        return ans;
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    
    vector<int> nums = {1,2,3,1,1,3};

    Solution sl;
    cout << sl.smallerNumbersThanCurrent(nums);
}