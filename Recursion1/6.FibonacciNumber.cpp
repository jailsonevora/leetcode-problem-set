#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
    //with memoization
    int fibMemo(int n, int memo[]) {

        if(n < 2)
            return n;

        if(!memo[n])
            return fib(n-1, memo) + fib(n-2, memo);

        return n;       
    }
public:
    int fib(int n) {

        if(n < 2)
            return n;

        return fib(n-1) + fib(n-2);       
    }    

    int fibM(int n) {
        int memo[n];
        fibMemo(n, memo);       
    }
    
};