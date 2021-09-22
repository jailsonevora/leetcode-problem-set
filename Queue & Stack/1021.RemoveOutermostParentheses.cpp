#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> stk;
        string ans = "";
        
        for(auto str: s){
            
            if(str == '(')
                stk.push(str);
            else if(str == ')'){
                char tmp = stk.top();
                stk.pop();
                if(!stk.empty()){
                    ans.push_back(tmp);
                    ans.push_back(str);
                }                                
            }
        }        
        return ans;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //string s = "(()())(())";
    string s = "(()())(())(()(()))";


    Solution sl;
    cout << sl.removeOuterParentheses(s);
}