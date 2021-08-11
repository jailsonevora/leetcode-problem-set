#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<string> tokens  {"2","1","+","3","*"};
    //vector<string> tokens  {"4","13","5","/","+"};
    //vector<string> tokens  {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << sl.evalRPN(tokens);
}