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
    //with dp bottom up approach
    int climbStairs(int n) {       
        int memo[3] = {1,2};
        for(int i=2; i < n; ++i)    
            memo[i % 3] = memo[(i-1) % 3] + memo[(i-2) % 3];        
        
        return memo[(n-1) % 3];
    }
};

int main(){

    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int n = 3;
    int memo[45] = {0};

    Solution sl;
    cout << sl.climbStairs(n);
}