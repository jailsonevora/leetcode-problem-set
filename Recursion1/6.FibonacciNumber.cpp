#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    int fib(int n) {

        if(n < 2)
            return n;

        return fib(n-1) + fib(n-2);       
    }
    
};