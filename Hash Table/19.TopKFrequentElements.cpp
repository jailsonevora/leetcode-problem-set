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

    struct compare 
    { 
        bool operator()(node const& a, node const& b)
        {
            return a.val < b.val;
        } 
    };  
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for(auto it: nums)
            mp[it]++;

        priority_queue<node,vector<node>,compare> heap;
        for(auto it: mp)
            heap.push(node(it.first,it.second));
        
        vector<int> ans;
        while (k--)
        {   
            ans.push_back(heap.top().key);
            heap.pop();
        }   
        return ans;
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