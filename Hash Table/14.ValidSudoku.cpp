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
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board.size(); ++j){
                if(board[i][j] != '.'){
                    if(!se.insert(board[i][j] +" in row "+i).second ||
                      !se.insert(board[i][j] +" in col "+j).second ||
                      !se.insert(board[i][j] +" in box "+i/3+" "+j/3).second ||
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