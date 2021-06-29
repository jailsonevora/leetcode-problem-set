#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ch;
        for (int i = 0; i < s.size(); i++)
                ch[s[i]]  = ch[s[i]] + 1;
        
        for (int i = 0; i < s.size(); i++)
            if(ch[s[i]] == 1)
                return i;
        return -1;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //string s = "leetcode";
    string s = "aabb";

    Solution sl;
    sl.firstUniqChar(s);
}