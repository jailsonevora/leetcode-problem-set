#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> stk;
        string ans;
        
        for(auto str: s){
            
            if(str == '(')
                stk.push(str);
            else if(str == ')'){
                if(!stk.empty()){
                    ans.push_back(stk.top());
                    ans.push_back(str);
                }
                stk.pop();                
            }
        }
        
        return ans;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    string s = "(()())(())";

    Solution sl;
    cout << sl.removeOuterParentheses(s);
}