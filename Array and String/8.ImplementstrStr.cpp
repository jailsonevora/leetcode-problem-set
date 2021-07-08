#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(!needle.size())
            return 0;

        for (int i = 0; i < haystack.size() - needle.size(); i++)
            if (haystack.substr(i,i+needle.size()) == needle)
                return i;
        return -1;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //cout << sl.strStr("","");
    //cout << sl.strStr("hello","ll");
    //cout << sl.strStr("a","a");
    cout << sl.strStr("aaa","a");
}