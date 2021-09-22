#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    string s = "(1+(2*3)+((8)/4))+1";

    Solution sl;
    cout << sl.maxDepth(s);
}