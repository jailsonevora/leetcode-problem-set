#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include <ctype.h>

using namespace std;

class Solution {
public:
    //"3[a]2[bc]";
    string decodeString(string s) {
        stack<int> nums;
        stack<string> ch;

        string ans = "";        
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {   
            if(isdigit(s[i])){
                count = 10 * count + ((s[i]) - '0');
            }
            else if (isalpha(s[i])) {
                ans += s[i];
            }
            else if(s[i] == '['){
                nums.push(count);
                ch.push(ans);
                count = 0;
                ans.clear();
            }
            else if(s[i] == ']'){
                for (int j = 1; j < nums.top(); j++)
                    ch.top() += ans;
                nums.pop();
                ans = move(ch.top());
                ch.pop();
            }
        }
        return ans;       
    }
    string decodeString(string s) {
        string curr;
        vector<int> nums;
        vector<string> strs;
        int n = 0;
        for (const auto& c: s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else if (isalpha(c)) {
                curr += c;
            } else if (c == '[') {
                nums.emplace_back(n);
                strs.emplace_back(curr);
                n = 0;
                curr.clear();
            } else if (c == ']') {
                for (; nums.back() > 0; --nums.back()) {
                    strs.back() += curr;
                }
                nums.pop_back();
                curr = move(strs.back()); strs.pop_back();
            }
        }
        return curr;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s = "3[a]2[bc]";
    //string s = "3[a2[c]]";
    //string s = "2[abc]3[cd]ef";
    //string s = "abc3[cd]xyz";
 
    Solution sl;
    cout << sl.decodeString(s);
}