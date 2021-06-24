#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;

        for (int i = 0; i < s.size() && i < t.size(); i++){
            if(mp.count(s[i]) && mp[s[i]] )
                mp.insert(make_pair(s[i],t[i]));

            if(mp.count(s[i]) && mp[s[i]] == t[i] )

        }
        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s = "egg", t = "add";
 
    Solution sl;
    sl.isIsomorphic(s,t);
}