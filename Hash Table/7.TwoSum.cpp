#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(target-nums[i]) > 0)
                return vector<int> {mp[target-nums[i]],i};            
            mp.insert(make_pair(nums[i],i));            
        }
        return vector<int> {};     
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n1 = {2,7,11,15};
    int n2 = 9;
 
    Solution s;
    s.twoSum(n1,n2);
}