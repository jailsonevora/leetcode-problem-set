#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;

        for (int i = 0; i < s.size(); i++){
            if(mp.count(s[i]) && mp[s[i]] != t[i] )
                return false;
            else if(mp.count(t[i]))
                return false;           
            mp.insert(make_pair(s[i],t[i]));
        }
        return true;        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //string s = "egg", t = "add";
    string s = "foo", t = "bar";
    //string s = "paper", t = "title";
    //string s = "badc", t = "baba";

 
    Solution sl;
    sl.isIsomorphic(s,t);
}