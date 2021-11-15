#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> stk;

        for(auto c: s){
            if(!stk.empty() && stk.top() == c)
                stk.pop();
            else
                stk.push(c);
        }

        string ans;
        while (!stk.empty())
            ans.push_back(stk.top()),
                stk.pop();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string removeDuplicates(string S) {
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }
};

int main(){

    //ex1
    //string s = "abbaca";

    //ex2
    string s = "azxxzy";

    Solution sl;
    cout << sl.removeDuplicates(s);

}