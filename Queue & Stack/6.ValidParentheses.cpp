#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> stck;

        for (char ch: s)
        {
            stck.push(ch);
        }
        
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    string s = "()";

   cout << sl.isValid(s) << "\n";
}