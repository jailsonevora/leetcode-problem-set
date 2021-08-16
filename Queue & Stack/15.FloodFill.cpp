#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

class Solution {
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
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
    }
};