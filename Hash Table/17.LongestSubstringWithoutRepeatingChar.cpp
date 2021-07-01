#include<iostream>
#include<unordered_Map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string lgstStr = {};

        if(s.size() == 1)
            return 1;

        for (int i = 0; i < s.size(); i++){
            string temp = {s[i]};
            for (int j = i+1; j < s.size(); j++){               
                if(temp.find(s[j]) == string::npos){
                    temp += std::string(1,s[j]);
                    if(temp.size() > lgstStr.size())
                        lgstStr = temp; 
                }
                else{
                    if(temp.size() > lgstStr.size())
                        lgstStr = temp;
                    break;
                }                 
            }
        }
        return lgstStr.size();
    }

    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        unordered_map<char,int> mp;
        for (int i = 0, j = 0; j < s.size(); i++, ++j){
            if(mp.count(s[j]))
                i = 
        }

    }


};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //string s = {"abcabcbb"};
    //string s = {"bbbbb"};
    //string s = {"pwwkew"};
    //string s = {"au"};
    //string s = {"dvdf"};
    string s = {"anviaj"};


    Solution sl;
    sl.lengthOfLongestSubstring(s);

}