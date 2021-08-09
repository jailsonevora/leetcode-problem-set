#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:

    void DFS(vector<vector<char>> &grid, int x, int y, int r, int c){
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1')
            return;
        
        grid[x][y] = '2';

        //recursive call to 4 adjacent directions
        DFS(grid, x+1, y, r, c);
        DFS(grid, x, y+1, r, c);
        DFS(grid, x-1, y, r, c);
        DFS(grid, x, y-1, r, c);
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        if(rows == 0)
            return 0;

        int cols = grid[0].size();

        int ans = 0;

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == '1')
                {   
                    DFS(grid, r,c, rows, cols);
                    ans++;
                }
        return ans;        
    }
};