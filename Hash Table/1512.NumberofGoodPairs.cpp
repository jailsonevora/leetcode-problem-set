#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    // Using Unordered Map - Effectively
    int numIdenticalPairs(vector<int>& nums) {
		
        unordered_map<int, int> mp;
		int ans = 0;

		for(int num : nums)
			ans += mp[num]++;

		return ans;
    }

    //Using Frequency Array
    // int numIdenticalPairs(vector<int>& nums) {
        
    //     int ans = 0;
    //     int count[101] = {};
        
    //     for (auto num: nums){
    //         ans += count[num];
    //         count[num]++;
    //     }
        
    //     return ans;
    // }

    // // using map
    // int numIdenticalPairs(vector<int>& nums) {
        
    //     unordered_map<int, int> tmp;
        
    //     for(auto n: nums)
    //         tmp[n]++;
        
    //     int ans = 0;
    //     for(auto [key, value] :tmp)
    //         ans += floor(value * (value - 1)/2);
        
    //     return ans;        
    // }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //string s = "abacbc";
    vector<int> nums = {1,2,3,1,1,3};

    Solution sl;
    cout << sl.numIdenticalPairs(nums);
}