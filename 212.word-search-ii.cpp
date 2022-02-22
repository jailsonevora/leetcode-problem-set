/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * {212} Word Search II
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    }
};
// @lc code=end
int main(){

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }; 
    vector<string> words = {"oath","pea","eat","rain"};

    Solution sl;
    sl.findWords(board,words);
}
