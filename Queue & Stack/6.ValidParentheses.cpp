#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        //valid parentheses is only even
        if(s.size() % 2 != 0)
            return false;

        stack<char> stck;

        for (char ch: s)
        {   
            if(ch == '(' || ch ==  '[' || ch == '{')
                stck.push(ch);
            else if( (ch == ')' && !stck.empty() && stck.top() == '(')
                || (ch == '}' && !stck.empty() && stck.top() == '{')
                || (ch == ']' && !stck.empty() && stck.top() == '[') 
            ){
                stck.pop();
            }
        }
        return stck.empty();
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    string s = "()";
    //string s = "()[]{}";
    //string s = "(]";
    //string s = "([)]";
    //string s = "{[]}";
    
    cout << sl.isValid(s) << "\n";
}