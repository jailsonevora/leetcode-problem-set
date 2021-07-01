#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<string> st;

        for (int i = 0; i < s.size(); i++){
            string temp = {s[i]};
            for (int j = i+1; j < s.size(); j++){
                temp += std::string(1,s[j]);
                st.insert(temp);
            }
        }

        return 0;
        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s = {"abcabcbb"};
    Solution sl;
    sl.lengthOfLongestSubstring(s);

}