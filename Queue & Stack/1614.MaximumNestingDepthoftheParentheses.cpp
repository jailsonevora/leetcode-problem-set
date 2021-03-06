#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        int max = 0, count = 0;
        for(auto str: s){
            
            if(str == '(')
                max = std::max(max, ++count),
                    st.push(str);
            
            else if(str == ')')
                    st.pop(),
                        count--;
        }
        return max;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    string s = "(1+(2*3)+((8)/4))+1";

    Solution sl;
    cout << sl.maxDepth(s);
}