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
            if (i >= s.length()) 
                break;
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
        return ans;
    }

    string reverseWords(string s) {
        if (s.empty())  return s;
        
        while(s.back() == ' ')                      //remove the space at end, after reversing the string, there is no space at beginning
            s.pop_back();
        reverse(s.begin(), s.end());                
        s.push_back(' ');                           //add a space at the end, space is used to identify a complete word.
        
        string::iterator start = s.begin();
        for (string::iterator itr = s.begin(); itr != s.end(); itr++){                  //reverse each single word
            if (*itr == ' '){
                reverse(start, itr);
                start = next(itr);                  //do not include space
            }
        }
    
        while(s.back() == ' ')                      //remove all extra spaces
            s.pop_back();  
        int i=0;
        while(i<s.size()){
            if (s[i] == ' ' && s[i+1] == ' '){
                s.erase(i+1, 1);
                continue;
            }
            i++;
        }
        
        return s;
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