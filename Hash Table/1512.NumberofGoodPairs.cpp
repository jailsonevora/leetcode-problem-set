#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int, int> tmp;
        
        for(auto n: nums)
            tmp[n]++;
        
        int ans = 0;
        for(auto [key, value] :tmp)
            ans += floor(value * (value - 1)/2);
        
        return ans;        
    }
};