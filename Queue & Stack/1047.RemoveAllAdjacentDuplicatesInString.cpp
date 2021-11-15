#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> stack;

        for(auto c: s){
            if(stack.top() == c)
                stack.pop();
            else
                stack.push(c);
        }
        
    }
};

int main(){

    //ex1
    string s = "abbaca";

    //ex2
    //string s = "azxxzy";

    Solution sl;
    sl.removeDuplicates(s);

}