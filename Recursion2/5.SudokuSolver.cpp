#include<iostream>
#include<vector>
#include <string.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<vector<char>> board = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    // recursive
    sl.solveSudoku(board);
}