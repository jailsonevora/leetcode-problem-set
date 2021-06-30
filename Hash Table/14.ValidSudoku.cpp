#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        char c = '9';
        unordered_map<int,int> mp;
        unordered_set<char> se;
        for (std::vector<char> row: board){
            for (char val: row){
                if(se.count(val))
                    return false;
                se.insert(val);
            }
        }
        

        
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