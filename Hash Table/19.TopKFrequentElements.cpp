#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    struct node
    {
        int key;
        int val;
        node(int k, int v) : key(k), val(v) {}
    };

    static int cmp(node const& a, node const& b)
    {
        return a.val < b.val;
    }    
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for(auto it: nums)
            mp[it]++;

        priority
        
        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {   
            v.push_back(mp)
        }
        
        

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