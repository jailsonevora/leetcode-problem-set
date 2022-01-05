/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    int bottomUp(vector<vector<char>> & matrix){

        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxelement = 0;

        for (int row = 1; row <= m; row++)
            for (int col = 1; col <= n; col++){
                if(matrix[row-1][col-1] == '1'){
                    dp[row][col] = 
                        1 + min(dp[row-1][col],
                                min(dp[row][col-1], dp[row-1][col-1]));
                    if(maxelement < dp[row][col])
                        maxelement = dp[row][col];
                }
            }
        return maxelement*maxelement;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return bottomUp(matrix);
    }
};
// @lc code=end

int main(){
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };

    Solution sl;
    cout << sl.maximalSquare(matrix);
}

