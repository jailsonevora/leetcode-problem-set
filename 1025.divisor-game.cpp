/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool divisorGameEven(int n) {
        return n % 2 == 0;     
    }
    // dp tabulation
    bool divisorGameTabulation(int n) {
        
        bool dp[n+1];
        std::fill(dp,dp+n+1,false);

        for(int i=2; i <= n; i++)
            for(int j = 1; j*j <= i;j++)
                if(i % j == 0 && !dp[i - j])
                    dp[i] = true;
        
        return dp[n];
    }

    bool divisorGame(int n) {
        //return divisorGame(n);
        return divisorGameTabulation(n);    
    }
};
// @lc code=end
int main(){

    int n = 2;
    Solution sl;
    
    cout << sl.divisorGame(n);
}
