#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        vector<int> ans;

        for(auto str: words)
            mp[str]++;

        set<pair<int, string>> st;

        for(auto [key, value]: mp)
            st.insert({value,key});

        for (int i = 0; i < k; i++)
        
        

        return {};
        
    }
};

int main(){

    vector<string> words = {
        "i","love","leetcode","i","love","coding"
    };

    int k = 2;
    
    Solution sl;
    sl.topKFrequent(words, k);
}