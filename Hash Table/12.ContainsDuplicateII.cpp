#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for (int i = 0; i < nums.size(); i++){
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k )
                    return true;
            mp[nums[i]] = i; 
        }
        return false;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    // vector<int> nums = {1,2,3,1};
    // int k = 3;

    vector<int> nums = {1,0,1,1};
    int k = 1;

    // vector<int> nums = {1,2,3,1,2,3};
    // int k = 2;

    Solution sl;
    sl.containsNearbyDuplicate(nums, k);
}