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

