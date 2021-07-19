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
        int prevToken = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + prevToken, s.begin() + i);
                prevToken = i+1;
            }
        }
        reverse(s.begin() + prevToken, s.end());
        return s;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;   
    //string s = "Let's take LeetCode contest";
    string s = "God Ding";

   sl.reverseWords(s);
}

95.24%