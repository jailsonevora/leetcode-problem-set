/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
    // find path compression
    int _find(unordered_map<int,int>& parent, int v){
        if(v == parent[v])
            return v;
        return parent[v] = _find(parent,parent[v]);
    }
    void _union(unordered_map<int,int>& parent, int u, int v){
        
        u = _find(parent,u);
        v = _find(parent,v);
        
        if(v != u)
            parent[u] = v;
    }
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> parent;
        for (int i = 0; i < nums.size(); i++)
            parent[nums[i]] = nums[i];

        unordered_set<int> set;
        for(auto i:nums)
            set.insert(i);

        // checking if the exists a element consecutive inferior than i in the set
        for(auto i:nums)
            if(set.count(i-1))
                _union(parent,i,i-1);

        // checking which DSU is having maximum elements
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0; i < nums.size(); i++) {
            int u = _find(parent,i);
            mp[u]++;
            ans = max(ans,mp[u]);
        }
        return ans;
    }
};
// @lc code=end
int main(){

    vector<int> nums = {100,4,200,1,3,2};
    //vector<int> nums = {0,-1};

    Solution sl;
    cout << sl.longestConsecutive(nums);
}
