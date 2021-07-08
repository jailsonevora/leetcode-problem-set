#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        unordered_map<string,int> mp;
        
        for (int i = 0; i < strs.size(); i++){
            for (int j = 1; j <= strs[i].size(); ++j)
                mp[strs[i].substr(0,j)]++;
        }
        mp.size();
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    vector<string> v = {"flower","flow","flight"};
    cout << sl.longestCommonPrefix(v);
}