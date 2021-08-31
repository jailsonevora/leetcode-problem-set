#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // iterativelly
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = 0, col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;        
    }

    //recursive
    bool searchMatrix(vector<vector<int>>& matrix, int target, int row, int col) {

        if(row >= matrix.size() || col < 0)
            return false;
        
        if(matrix[row][col] == target)
                return true;

        if(matrix[row][col] > target)
            return searchMatrix(matrix, target, row, col - 1);
        else
            return searchMatrix(matrix, target, row + 1, col);
    }

};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<vector<int>> mat = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    cout << sl.searchMatrix(mat, 5);
}