#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    void DFS(vector<vector<int>> &grid, int x, int y, int r, int c){
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != 1)
            return;
        
        grid[x][y] +=1 ;

        //recursive call to 4 adjacent directions
        DFS(grid, x+1, y, r, c);
        DFS(grid, x, y+1, r, c);
        DFS(grid, x-1, y, r, c);
        DFS(grid, x, y-1, r, c);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (mat[r][c] == 1)
                {   
                    DFS(mat, r,c, rows, cols);
                }
        return mat;    
    }
};