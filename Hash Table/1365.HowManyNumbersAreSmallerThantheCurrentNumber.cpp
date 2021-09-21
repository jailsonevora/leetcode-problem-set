#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // using sorting
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i)
            ans[i] = abs(nums.size() - (i+1));        
        return ans; 
    }

    // brute force
    // vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
    //     vector<int> ans(nums.size(), 0);
        
    //     // brute force
    //     for(int i = 0; i < nums.size(); ++i)
    //         for(int j = 1; j < nums.size(); j++)
    //             if(nums[j] < nums[i])
    //                 ans[i]++;
    //     return ans;
    // }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> nums = {8,1,2,2,3};

    Solution sl;
    for(auto num: sl.smallerNumbersThanCurrent(nums))
        cout << num << "\n";
}