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

        auto comp = [&](const pair<int,string>& a, const pair<int,string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };

        typedef priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comp)> m_priority_queue;
        m_priority_queue pq(comp);

        for(auto [key, value]: mp)
            pq.push({value,key});

        for (int i = 0; i < k; i++)
            ans.push_back(pq.top().second),
                pq.pop();
        return ans;
    }
};

int main(){

    // vector<string> words = {
    //     "i","love","leetcode","i","love","coding"
    // };

    // int k = 2;

    vector<string> words = {
        "the","day","is","sunny","the","the","the","sunny","is","is"
    };

    int k = 4;
    
    Solution sl;
    sl.topKFrequent(words, k);
}