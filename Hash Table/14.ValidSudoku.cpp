#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> se;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board.size(); ++j)
                if(board[i][j] != '.')
                    if( !se.insert(std::string(1,board[i][j]).append(" in row ").append(1,i)).second ||
                        !se.insert(std::string(1,board[i][j]).append(" in col ").append(1,j)).second ||
                        !se.insert(std::string(1,board[i][j]).append(" in box ").append(1,(i/3)).append(1,(j/3)) ).second
                      )
                        return false;
        return true;        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<vector<char>> board;

    Solution sl;
    sl.isValidSudoku(board);
}