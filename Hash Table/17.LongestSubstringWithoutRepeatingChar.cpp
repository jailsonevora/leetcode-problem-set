#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {

        unordered_set<string> st;
        string lgstStr = {};

        string temp = {s[0]};
        for (int i = 0, j = i+1; j < s.size(); ++i, j++){
            if(temp.find(s[j]) == string::npos)
                temp += std::string(1,s[j]);
            else{
                if(temp.size() > lgstStr.size())
                    lgstStr = temp;
                i=j;
                temp = s[j];
            }                    
        }
        return lgstStr.size();
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //string s = {"abcabcbb"};
    //string s = {"bbbbb"};
    string s = {"pwwkew"};

    Solution sl;
    sl.lengthOfLongestSubstring(s);

}