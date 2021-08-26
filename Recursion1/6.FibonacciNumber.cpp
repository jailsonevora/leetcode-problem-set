#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    //with memoization
    int fibMemo(int n, int memo[]) {

        if(n < 2)
            return n;

        if(!memo[n])
            return fibMemo(n-1, memo) + fibMemo(n-2, memo);
        return n;       
    }
    int fib(int n) {

        if(n < 2)
            return n;
        return fib(n-1) + fib(n-2);       
    }
};

int main(){

    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int n = 3;
    int memo[n];

    Solution sl;
    cout << sl.fibMemo(n, memo);
}