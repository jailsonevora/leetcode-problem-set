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
    void _union(unordered_map<int,int>& parent, unordered_map<int,int>& size, int u, int v){
        
        u = _find(parent,u);
        v = _find(parent,v);
        
        if(v != u){
            if(size[u]<size[v])
                swap(u,v);
            parent[v] = u;
            size[u]+=size[v];            
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {

        if(!nums.size())
            return 0;

        unordered_map<int,int> parent,size;
        for (int i = 0; i < nums.size(); i++)
            parent[nums[i]] = nums[i],
            size[nums[i]]=1;

        unordered_set<int> set;
        for(auto i:nums)
            set.insert(i);

        // checking if the exists a element consecutive inferior than i in the set
        for(auto i:nums)
            if(set.count(i-1))
                _union(parent,size,i,i-1);

        // checking which DSU is having maximum elements
        pair<int,int> max = *max_element(size.begin(), size.end(), 
            [](pair<int,int> s1, pair<int,int> s2) {
            return s1.second < s2.second;    
        });
        return max.second;
    }
};
// @lc code=end
int main(){

    //vector<int> nums = {100,4,200,1,3,2};
    //vector<int> nums = {0,-1};
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    Solution sl;
    cout << sl.longestConsecutive(nums);
}
