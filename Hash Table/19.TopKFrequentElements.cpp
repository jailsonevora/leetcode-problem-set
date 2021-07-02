#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(auto it: nums)
            mp[it]++;

        return vector<int>{};
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n = {1,1,1,2,2,3};
    int k = 2;
 
    Solution s;
    s.topKFrequent(n,k);
}