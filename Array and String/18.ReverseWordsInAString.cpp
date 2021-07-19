#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = 0;

        while (i < s.length())
        {
            while (i < s.length() && s[i] == ' ')
                ++i;
            if (i >= s.length()) break;
            int j = i+1;
            while (j < s.length() && s[j] != ' ')
                ++j;
                string subStr = s.substr(i, j-i);
                if (ans.length() == 0)
                    ans = subStr;
                else
                    ans = subStr + " " + ans;
                i = j+1;
        }
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;   
    string s = "the sky is blue";
    // string s = "  hello world  ";
    // string s = "a good   example";
    // string s = "  Bob    Loves  Alice   ";
    // string s = "Alice does not even like bob";

   sl.reverseWords(s);
}