#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    struct node
    {
        string key;
        int val;
        node(string k, int v) : key(k), val(v) {}
    };

    struct compare 
    { 
        bool operator()(node const& a, node const& b)
        {
            if(a.val >= b.val){
                if(a.key.compare(b.key) > 0)
                    return a.val > b.val;
            } 
            return a.val <= b.val;
        } 
    }; 
    string longestCommonPrefix(vector<string>& strs) {

        unordered_map<string,int> mp;       
        
        for (int i = 0; i < strs.size() && !strs[i].empty(); i++){
            for (int j = 1; j <= strs[i].size() && !strs[i].empty(); ++j)
                mp[strs[i].substr(0,j)]++;
        }
        priority_queue<node,vector<node>,compare> heap;
        for(auto it: mp)
            heap.push(node(it.first,it.second));
        
        if(heap.empty())
            return "";
        
        string ans = (heap.top().val == strs.size()) ? heap.top().key : "";
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //vector<string> v = {"flower","flow","flight"};
    //vector<string> v = {"dog","racecar","car"};
    //vector<string> v = {""};
    vector<string> v = {"flower","flawer","flvwer","flower"};

    cout << sl.longestCommonPrefix(v);
}