#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            mp[strs[i]].push_back(sortedStr);
        }
        
        vector<vector<string>> result;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
            result.push_back(itr->second);        
    }
};


int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    //vector<string> strs = {""};
    //vector<string> strs = {"a"};


    Solution sl;
    sl.groupAnagrams(strs);
}