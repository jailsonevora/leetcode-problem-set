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
#include<map>

using namespace std;

class Solution {
    // find path compression
    int _find(vector<int>& parent, int v){
        if(v == parent[v])
            return v;
        return parent[v] = _find(parent,parent[v]);
    }

    void _union(vector<int>& parent, int u, int v){
        
        u = _find(parent,u);
        v = _find(parent,v);
        
        if(v != u)
            parent[u] = v;
    }
public:
    int longestConsecutive(vector<int>& nums) {

        vector<int> parent(nums.size(),0);
        for (int i = 0; i < nums.size(); i++)
            parent[i] = i;

        unordered_set<int> set;
        for(auto i:nums)
            set.insert(i);

        for(auto i:nums)
            if(set.count(i-1))
                _union(parent,i,i-1);
        
        return 0;
    }
};
// @lc code=end
int main(){

    vector<int> nums = {100,4,200,1,3,2};

    Solution sl;
    cout << sl.longestConsecutive(nums);
}
