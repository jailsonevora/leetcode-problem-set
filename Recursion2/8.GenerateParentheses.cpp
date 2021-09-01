#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

class Solution {
    void backtracking(vector<string> &ans, string cur, int openParentheses, int closeParentheses, int n){
        if(cur.size() == n * 2){
            ans.push_back(cur);
            return;
        }

        if(openParentheses < n)
            backtracking(ans, cur+"(", openParentheses+1, closeParentheses, n);

        if(closeParentheses < openParentheses)
            backtracking(ans, cur+")", openParentheses, closeParentheses+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans,"", 0, 0, n);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    int n;
    
    // recursive backtracking
    sl.generateParenthesis(n = 3);
}