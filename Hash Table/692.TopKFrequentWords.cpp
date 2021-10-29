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
        vector<string> ans;

        for(auto str: words)
            mp[str]++;

        //set<pair<int, string>> st;
        priority_queue< 
            pair<int,string>, 
            vector<pair<int,string>>, 
            less<>
        >
        pq;

        for(auto [key, value]: mp)
            pq.push({value,key});

        for (int i = 0; i < k; i++)
            ans.push_back(pq.top().second),
                pq.pop();
        
        return ans;
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