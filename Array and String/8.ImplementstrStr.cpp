#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>

using namespace std;

class Solution {
public:
    //with substring
    int strStr(string haystack, string needle) {

        if(haystack.size() < needle.size()) return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++){
            if (haystack.substr(i,needle.size()) == needle)
                return i;
        }
        return -1;
    }

    //with string
    int strStr(string haystack, string needle) {

        if(haystack.size() < needle.size()) return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
            if (string(haystack.begin()+i,haystack.begin()+i+needle.size()) == needle)
                return i;
        return -1;
    }    

    //with map
    int strStr(string haystack, string needle) {

        unordered_map<string, int> mp;

        if(!needle.size())
            return 0;

        if(haystack.size() < needle.size()) return -1;

        for (int i = 0; i <= haystack.size()-needle.size(); i++)
            if(!mp.count(haystack.substr(i,needle.size())))
                mp[haystack.substr(i,needle.size())] = i;

        if(mp.find(needle) != mp.end())
            return mp[needle];
        else
            return -1;

    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //cout << sl.strStr("","");
    cout << sl.strStr("hello","ll");
    //cout << sl.strStr("a","a");
    //cout << sl.strStr("aaa","a");
}