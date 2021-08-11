#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
    int eval(string operators, int pop1, int pop2){
        if(operators == "+")
            return pop1 + pop2;
        else if(operators == "-")
            return pop1 - pop2;
        else if(operators == "/")
            return pop1 / pop2;
        else if(operators == "*")
            return pop1 * pop2;
    }
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> operand;

        for(auto& str: tokens){
            if(!operand.empty() && str == "+" || str == "-" || str == "/" || str == "*"){
                int pop1 = operand.top();
                operand.pop();
                int pop2 = operand.top();
                operand.pop();

                operand.push(eval(str, pop1, pop2));
            }
            else
                operand.push(stoi(str));
        }
        return operand.top();        
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