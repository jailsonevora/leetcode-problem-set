#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>
#include<string>
#include<array>
#include <string.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        int temp = abs(n);
        double ans = myPow(x*x, temp/2) * (temp%2 ? x : 1);
        return (n>0 ? ans : 1/ans);
    }
};