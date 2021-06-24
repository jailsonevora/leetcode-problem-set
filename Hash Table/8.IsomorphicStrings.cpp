#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:

    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mps{0}, mpt{0};

        for (int i = 0; i < s.size(); i++){
            if( mps[s[i]] != mpt[t[i]])
                return false;
            mps[s[i]] = i+1;
            mpt[t[i]] = i+1;
        }
        return true;        
    }

    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;

        for (int i = 0; i < s.size(); i++){
            if( mp.count(s[i]) ){
                if(mp[s[i]] != t[i])
                    return false;
            }
            else{ 
                for (unordered_map<char,char>::iterator it=mp.begin(); it!=mp.end(); ++it)
                    if(it->second == t[i])
                        return false;                  
                mp.insert(make_pair(s[i],t[i]));
            }
        }
        return true;        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //string s = "egg", t = "add";
    //string s = "foo", t = "bar";
    string s = "paper", t = "title";
    //string s = "badc", t = "baba";

 
    Solution sl;
    sl.isIsomorphic(s,t);
}